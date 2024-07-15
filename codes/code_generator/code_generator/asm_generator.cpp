#include "asm_generator.h"
#include <iostream>
#include <fstream>
#include <filesystem>

AsmGenerator::AsmGenerator() : tab("\t"), error(false) {}

bool AsmGenerator::hasError()
{
	return error;
}

void AsmGenerator::generateCode(const ProgramSummary *programSummary)
{
	// https://hackmd.io/@YuminChiang/S1eAT8PSo

	// Create output directory and file.
	asmFile.open("out.asm");
	asmFile << "ORG 100h" << std::endl
			<< std::endl;
	asmFile << "JMP proc_main" << std::endl;
	// Variables and constants declaration.
	asmFile << "section .data" << std::endl;
	writeConstantDeclaration(programSummary->allConstants);
	asmFile << "section .bss" << std::endl;
	writeVariableDeclaration(programSummary->allVariables);
	asmFile << std::endl;

	// Write assembly code of functions.
	asmFile << "section .text" << std::endl;
	if (programSummary->hasPrintf)
		writePrintfFunction();
	if (programSummary->hasScanf)
		writeScanfFunction();
	for (Function function : programSummary->functions)
	{
		writeFunction(function);
	}

	asmFile.close();
}

void AsmGenerator::writeVariableDeclaration(const std::vector<Identifier *> variables)
{
	for (Identifier *variable : variables)
	{
		asmFile << tab << variable->globalId << ": ";

		if (variable->dataType == DataType::INT)
			asmFile << "resb 4" << std::endl;
	}
}

void AsmGenerator::writeConstantDeclaration(const std::vector<Constant *> constants)
{
	for (Constant *constant : constants)
	{
		asmFile << tab << constant->globalId;

		if (constant->type == Constant::NUM)
			asmFile << " dw " << constant->value;
		else if (constant->type == Constant::STR)
			asmFile << " db '" << constant->value << "', '$'";

		asmFile << std::endl;
	}

	asmFile << tab << "_newline db 13, 10, '$'" << std::endl;
}

void AsmGenerator::writePrintfFunction()
{
	// Print string.
	asmFile << "_proc_print_string:" << std::endl;
	asmFile << tab << "MOV dx, ax" << std::endl;
	asmFile << tab << "MOV ah, 09h" << std::endl;
	asmFile << tab << "INT 21h" << std::endl;
	asmFile << tab << "RET" << std::endl;

	// Print number.
	// https://www.geeksforgeeks.org/8086-program-to-print-a-16-bit-decimal-number/
	asmFile << "_proc_print_number:" << std::endl;
	asmFile << tab << "MOV cx, 0" << std::endl;
	asmFile << tab << "MOV dx, 0" << std::endl;
	asmFile << "_print_number_label:" << std::endl;
	asmFile << tab << "CMP ax, 0" << std::endl;
	asmFile << tab << "JE _print_number_print" << std::endl;
	asmFile << tab << "MOV bx, 10" << std::endl;
	asmFile << tab << "DIV bx" << std::endl;
	asmFile << tab << "PUSH dx" << std::endl;
	asmFile << tab << "INC cx" << std::endl;
	asmFile << tab << "XOR dx, dx" << std::endl;
	asmFile << tab << "JMP _print_number_label" << std::endl;
	asmFile << "_print_number_print:" << std::endl;
	asmFile << tab << "CMP cx, 0" << std::endl;
	asmFile << tab << "JE _print_number_exit" << std::endl;
	asmFile << tab << "POP dx" << std::endl;
	asmFile << tab << "ADD dx, 48" << std::endl;
	asmFile << tab << "MOV ah, 02h" << std::endl;
	asmFile << tab << "INT 21h" << std::endl;
	asmFile << tab << "DEC cx" << std::endl;
	asmFile << tab << "JMP _print_number_print" << std::endl;
	asmFile << "_print_number_exit:" << std::endl;
	asmFile << tab << "RET" << std::endl;

	// Print new line.
	asmFile << "_proc_print_new_line:" << std::endl;
	asmFile << tab << "LEA ax, _newline" << std::endl;
	asmFile << tab << "MOV dx, ax" << std::endl;
	asmFile << tab << "MOV ah, 09h" << std::endl;
	asmFile << tab << "INT 21h" << std::endl;
	asmFile << tab << "RET" << std::endl;
}

void AsmGenerator::writeScanfFunction()
{
	asmFile << "_proc_scan_number:" << std::endl;
	asmFile << tab << "MOV dx, 0" << std::endl;
	asmFile << "_scan_number_label:" << std::endl;
	asmFile << tab << "MOV ah, 01h" << std::endl;
	asmFile << tab << "INT 21h" << std::endl;
	asmFile << tab << "CMP al, 0dh" << std::endl;
	asmFile << tab << "JE _scan_number_exit" << std::endl;
	asmFile << tab << "CMP al, ' '" << std::endl;
	asmFile << tab << "JE _scan_number_exit" << std::endl;
	asmFile << tab << "MOV ah, 0" << std::endl;
	asmFile << tab << "SUB al, 48" << std::endl;
	asmFile << tab << "MOV bx, ax" << std::endl;
	asmFile << tab << "MOV ax, dx" << std::endl;
	asmFile << tab << "MOV dx, 10" << std::endl;
	asmFile << tab << "MUL dx" << std::endl;
	asmFile << tab << "ADD ax, bx" << std::endl;
	asmFile << tab << "MOV dx, ax" << std::endl;
	asmFile << tab << "JMP _scan_number_label" << std::endl;
	asmFile << "_scan_number_exit: " << std::endl;
	asmFile << tab << "MOV ax, dx" << std::endl;
	asmFile << tab << "RET" << std::endl;
}

void AsmGenerator::writeFunction(Function function)
{
	asmFile << "proc_" << function.name << ":" << std::endl;

	if (function.name != "main")
	{
		asmFile << tab << "PUSH bp" << std::endl;
		asmFile << tab << "MOV bp, sp" << std::endl;
		for (size_t i = 0; i < function.parameters.size(); i++)
		{
			asmFile << tab << "MOV ax, [bp + " << (i * 2 + 4) << "]" << std::endl;
			asmFile << tab << "MOV [" << function.parameters[function.parameters.size() - i - 1]->globalId << "], ax" << std::endl;
		}
	}

	writeStatements(function.statements);

	if (function.name == "main")
	{
		asmFile << tab << "MOV ah, 4ch" << std::endl;
		asmFile << tab << "INT 21h" << std::endl;
		asmFile << tab << "; ^^The program will terminate here." << std::endl;
	}
	else
	{
		if (function.returnDataType == DataType::VOID)
		{
			asmFile << tab << "POP bp" << std::endl;
			asmFile << tab << "RET" << std::endl;
		}
	}
}

void AsmGenerator::writeStatements(std::vector<Statement *> statements)
{
	for (Statement *statement : statements)
	{
		writeStatement(statement);
	}
}

void AsmGenerator::writeStatement(Statement *statement)
{
	static const char *labelName = "_statement_label_";
	static int unusedLabel = 0;
	static int lastLoopLabel = -1;

	const char *statementName = getTypeName(statement);
	if (statementName == AssignmentStatement::getTypeName())
	{
		AssignmentStatement *statePtr = dynamic_cast<AssignmentStatement *>(statement);

		writeExpression(statePtr->expression, "bx");
		if (statePtr->assignmentOperator == "+=")
		{
			asmFile << tab << "MOV ax, " << statePtr->variable->globalId << std::endl;
			asmFile << tab << "ADD ax, bx" << std::endl;
			asmFile << tab << "MOV bx, ax" << std::endl;
		}
		else if (statePtr->assignmentOperator == "-=")
		{
			asmFile << tab << "MOV ax, " << statePtr->variable->globalId << std::endl;
			asmFile << tab << "SUB ax, bx" << std::endl;
			asmFile << tab << "MOV bx, ax" << std::endl;
		}
		else if (statePtr->assignmentOperator == "*=")
		{
			asmFile << tab << "MOV ax, " << statePtr->variable->globalId << std::endl;
			asmFile << tab << "IMUL bx" << std::endl;
			asmFile << tab << "MOV bx, ax" << std::endl;
		}
		else if (statePtr->assignmentOperator == "/=")
		{
			asmFile << tab << "MOV ax, " << statePtr->variable->globalId << std::endl;
			asmFile << tab << "IDIV bx" << std::endl;
			asmFile << tab << "MOV bx, ax" << std::endl;
		}
		else if (statePtr->assignmentOperator == "%=")
		{
			asmFile << tab << "MOV ax, " << statePtr->variable->globalId << std::endl;
			asmFile << tab << "IDIV bx" << std::endl;
			asmFile << tab << "MOV ax, dx" << std::endl;
			asmFile << tab << "MOV bx, ax" << std::endl;
		}
		asmFile << tab << "MOV [" << statePtr->variable->globalId << "], bx" << std::endl;
	}
	else if (statementName == IfStatement::getTypeName())
	{
		IfStatement *statePtr = dynamic_cast<IfStatement *>(statement);
		const int thisLabel = unusedLabel++;

		writeExpression(statePtr->expression, "ax");
		asmFile << tab << "CMP ax, 1" << std::endl;
		asmFile << tab << "JNE " << labelName << thisLabel << "_jump1" << std::endl;
		writeStatements(statePtr->trueStatements);

		if (statePtr->elseStatements.size() != 0)
		{
			asmFile << tab << "JMP " << labelName << thisLabel << "_jump2" << std::endl;
			asmFile << labelName << thisLabel << "_jump1:" << std::endl;
			writeStatements(statePtr->elseStatements);
		}

		asmFile << labelName << thisLabel << "_jump" << (statePtr->elseStatements.size() == 0 ? "1" : "2") << ":" << std::endl;
	}
	else if (statementName == WhileStatement::getTypeName())
	{
		WhileStatement *statePtr = dynamic_cast<WhileStatement *>(statement);
		const int thisLabel = lastLoopLabel = unusedLabel++;

		asmFile << labelName << thisLabel << ":" << std::endl;
		writeExpression(statePtr->expression, "ax");
		asmFile << tab << "CMP ax, 1" << std::endl;
		asmFile << tab << "JNE " << labelName << thisLabel << "_exit" << std::endl;
		writeStatements(statePtr->statements);
		asmFile << tab << "JMP " << labelName << thisLabel << std::endl;
		asmFile << labelName << thisLabel << "_exit:" << std::endl;
	}
	else if (statementName == DoWhileStatement::getTypeName())
	{
		DoWhileStatement *statePtr = dynamic_cast<DoWhileStatement *>(statement);
		const int thisLabel = lastLoopLabel = unusedLabel++;

		asmFile << labelName << thisLabel << "_do:" << std::endl;
		writeStatements(statePtr->statements);
		asmFile << labelName << thisLabel << ":" << std::endl;
		writeExpression(statePtr->expression, "ax");
		asmFile << tab << "CMP ax, 1" << std::endl;
		asmFile << tab << "JE " << labelName << thisLabel << "_do" << std::endl;
		asmFile << labelName << thisLabel << "_exit:" << std::endl;
	}
	else if (statementName == ForStatement::getTypeName())
	{
		ForStatement *statePtr = dynamic_cast<ForStatement *>(statement);
		const int thisLabel = lastLoopLabel = unusedLabel++;

		writeStatement(statePtr->statements[0]);
		asmFile << labelName << thisLabel << "_cmp:" << std::endl;
		writeStatement(statePtr->statements[1]);
		asmFile << tab << "CMP ax, 1" << std::endl;
		asmFile << tab << "JNE " << labelName << thisLabel << "_exit" << std::endl;
		writeStatements(std::vector<Statement *>({statePtr->statements.begin() + 2, statePtr->statements.end() - 1}));
		asmFile << labelName << thisLabel << ":" << std::endl;
		writeStatement(statePtr->statements.back());
		asmFile << tab << "JMP " << labelName << thisLabel << "_cmp" << std::endl;
		asmFile << labelName << thisLabel << "_exit:" << std::endl;
	}
	else if (statementName == JumpStatement::getTypeName())
	{
		JumpStatement *statePtr = dynamic_cast<JumpStatement *>(statement);

		if (statePtr->type == JumpStatement::BREAK)
		{
			asmFile << tab << "JMP " << labelName << lastLoopLabel << "_exit" << std::endl;
		}
		else if (statePtr->type == JumpStatement::CONTINUE)
		{
			asmFile << tab << "JMP " << labelName << lastLoopLabel << std::endl;
		}
		else if (statePtr->type == JumpStatement::RETURN)
		{
			if (statePtr->returnExpre != NULL)
			{
				writeExpression(statePtr->returnExpre, "ax");
			}
			asmFile << tab << "POP bp" << std::endl;
			asmFile << tab << "RET" << std::endl;
		}
	}
	else if (statementName == ExpressionStatement::getTypeName())
	{
		ExpressionStatement *statePtr = dynamic_cast<ExpressionStatement *>(statement);
		writeExpression(statePtr->expression, "ax");
	}
	else if (statementName == EmptyStatement::getTypeName())
	{
		// Do nothing.
	}
	else
	{
		std::cout << "AsmGeneratorError: Unknown statement name: " << statementName << std::endl;
	}
}

void AsmGenerator::writeExpression(Expression *expression, const char *resultRegister)
{
	// https://www.geeksforgeeks.org/arithmetic-instructions-8086-microprocessor/
	static int unusedId = 0;

	const char *expreType = getTypeName(expression);
	if (expreType == TwoExpreExpression::getTypeName())
	{
		TwoExpreExpression *expre = dynamic_cast<TwoExpreExpression *>(expression);

		writeExpression(expre->expre1, "ax");
		asmFile << tab << "PUSH ax" << std::endl;
		writeExpression(expre->expre2, "bx");
		asmFile << tab << "POP ax" << std::endl;

		if (expre->expreOperator == "&&")
		{
			asmFile << tab << "AND ax, bx" << std::endl;
		}
		else if (expre->expreOperator == "||")
		{
			asmFile << tab << "OR ax, bx" << std::endl;
		}
		else if (expre->expreOperator == "==")
		{
			const int thisId = unusedId++;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JE _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
		else if (expre->expreOperator == "!=")
		{
			const int thisId = unusedId++;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JNE _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
		else if (expre->expreOperator == ">")
		{
			const int thisId = unusedId++;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JG _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
		else if (expre->expreOperator == "<")
		{
			const int thisId = unusedId++;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JL _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
		else if (expre->expreOperator == ">=")
		{
			const int thisId = unusedId++;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JGE _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
		else if (expre->expreOperator == "<=")
		{
			const int thisId = unusedId++;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JLE _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
		else if (expre->expreOperator == "+")
		{
			asmFile << tab << "ADD ax, bx" << std::endl;
		}
		else if (expre->expreOperator == "-")
		{
			asmFile << tab << "SUB ax, bx" << std::endl;
		}
		else if (expre->expreOperator == "*")
		{
			asmFile << tab << "MUL bx" << std::endl;
		}
		else if (expre->expreOperator == "/")
		{
			asmFile << tab << "MOV dx, 0" << std::endl;
			asmFile << tab << "DIV bx" << std::endl;
		}
		else if (expre->expreOperator == "%")
		{
			asmFile << tab << "MOV dx, 0" << std::endl;
			asmFile << tab << "DIV bx" << std::endl;
			asmFile << tab << "MOV ax, dx" << std::endl;
		}
	}
	else if (expreType == OneExpreExpression::getTypeName())
	{
		OneExpreExpression *expre = dynamic_cast<OneExpreExpression *>(expression);
		writeExpression(expre->expression, "ax");

		if (expre->expreOperator == "++")
		{
			asmFile << tab << "INC ax" << std::endl;

			if (typeid(*(expre->expression)).name() == ConstantExpression::getTypeName())
			{
				asmFile << tab << "MOV [" << dynamic_cast<ConstantExpression *>(expre->expression)->variable->globalId << "], ax" << std::endl;
			}
		}
		else if (expre->expreOperator == "--")
		{
			asmFile << tab << "DEC ax" << std::endl;

			if (typeid(*(expre->expression)).name() == ConstantExpression::getTypeName())
			{
				asmFile << tab << "MOV [" << dynamic_cast<ConstantExpression *>(expre->expression)->variable->globalId << "], ax" << std::endl;
			}
		}
		else if (expre->expreOperator == "!")
		{
			const int thisId = unusedId++;
			asmFile << tab << "MOV bx, 0" << std::endl;
			asmFile << tab << "CMP ax, bx" << std::endl;
			asmFile << tab << "JE _expre" << thisId << "_jump" << std::endl;
			asmFile << tab << "MOV ax, 0" << std::endl;
			asmFile << tab << "JMP _expre" << thisId << "_end" << std::endl;
			asmFile << "_expre" << thisId << "_jump:" << std::endl;
			asmFile << tab << "MOV ax, 1" << std::endl;
			asmFile << "_expre" << thisId << "_end:" << std::endl;
		}
	}
	else if (expreType == ConstantExpression::getTypeName())
	{
		ConstantExpression *expre = dynamic_cast<ConstantExpression *>(expression);
		if (expre->type == ConstantExpression::ID)
		{
			asmFile << tab << "MOV ax, [" << expre->variable->globalId << "]" << std::endl;
		}
		else if (expre->type == ConstantExpression::CONST)
		{
			if (expre->constant->type == Constant::NUM)
			{
				asmFile << tab << "MOV ax, [" << expre->constant->globalId << "]" << std::endl;
			}
			else if (expre->constant->type == Constant::STR)
			{
				asmFile << tab << "LEA ax, [" << expre->constant->globalId << "]" << std::endl;
			}
		}
	}
	else if (expreType == FunctionCallExpression::getTypeName())
	{
		// Move arguments to stack.
		FunctionCallExpression *expre = dynamic_cast<FunctionCallExpression *>(expression);
		for (Expression *argument : expre->arguments)
		{
			writeExpression(argument, "ax");
			asmFile << tab << "PUSH ax" << std::endl;
		}

		asmFile << tab << "CALL " << "proc_" << expre->functionName << std::endl;
	}
	else if (expreType == ReservedFunctionExpression::getTypeName())
	{
		ReservedFunctionExpression *expre = dynamic_cast<ReservedFunctionExpression *>(expression);
		if (expre->type == ReservedFunctionExpression::PRINTF)
		{
			std::vector<Expression *>::iterator it = expre->arguments.begin();
			for (Expression *strExpre : expre->constantStrings)
			{
				ConstantExpression *conExpre = dynamic_cast<ConstantExpression *>(strExpre);
				if (conExpre->constant->value == "%d")
				{
					if (it == expre->arguments.end())
					{
						printError("Wrong number of arguments in printf");
						return;
					}
					writeExpression(*it, "ax");
					asmFile << tab << "CALL _proc_print_number" << std::endl;
					it++;
				}
				else
				{
					writeExpression(conExpre, "ax");
					asmFile << tab << "CALL _proc_print_string" << std::endl;
				}
			}

			asmFile << tab << "CALL _proc_print_new_line" << std::endl;
		}
		else if (expre->type == ReservedFunctionExpression::SCANF)
		{
			std::vector<Expression *>::iterator it = expre->arguments.begin();
			for (Expression *strExpre : expre->constantStrings)
			{
				ConstantExpression *conExpre = dynamic_cast<ConstantExpression *>(strExpre);
				if (conExpre->constant->value == "%d")
				{
					if (it == expre->arguments.end())
					{
						printError("Wrong number of arguments in scanf");
						return;
					}

					asmFile << tab << "CALL _proc_scan_number" << std::endl;
					std::string variableName = dynamic_cast<ConstantExpression *>(*it)->variable->globalId;
					asmFile << tab << "MOV [" << variableName << "], ax" << std::endl;
					it++;
					asmFile << tab << "CALL _proc_print_new_line" << std::endl;
				}
			}
		}
	}
	else
	{
		std::cout << "AsmGeneratorError: Unknown expression type: " << expreType << std::endl;
	}

	if (resultRegister != "ax")
		asmFile << tab << "MOV " << resultRegister << ", ax" << std::endl;
}

void AsmGenerator::printError(std::string errorMessage)
{
	std::cerr << "Error: " << errorMessage << std::endl;
	error = true;
}

template <typename T>
const char *AsmGenerator::getTypeName(T *ptr)
{
	return typeid(*ptr).name();
}
