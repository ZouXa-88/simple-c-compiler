#include "code_scanner.h"
#include <iostream>
#include <algorithm>


CodeScanner::~CodeScanner()
{
	if (programSummary != NULL)
	{
		programSummary->clear();
		delete programSummary;
	}
}

const ProgramSummary* CodeScanner::scan(nlohmann::json jsonData)
{
	programSummary = new ProgramSummary;

	// Add custom function.
	if (jsonData["name"] == "FunctionList")
	{
		// For each function definition.
		std::set<std::string> allFunctionNames;
		std::string currentFunctionName = "";
		for (auto functionJson : jsonData["children"])
		{
			// Check if the function name is duplicated.
			currentFunctionName = toString(functionJson["value"]);
			if (allFunctionNames.find(currentFunctionName) == allFunctionNames.end())
				allFunctionNames.insert(currentFunctionName);
			else
			{
				printError("This function has been defined: " + currentFunctionName);
				continue;
			}
			
			programSummary->functions.push_back(Function
			(
				currentFunctionName,
				toDataType(toString(functionJson["children"][0]["value"]))
			));
			// Parameters.
			if (functionJson["children"][1]["children"] != NULL)
			{
				for (auto parameterJson : functionJson["children"][1]["children"][0]["children"])
				{
					Identifier* variable = new Identifier
					(
						toDataType(parameterJson["children"][0]["value"]),
						toString(parameterJson["children"][1]["value"]),
						currentFunctionName
					);
					programSummary->functions.back().parameters.push_back(variable);
					programSummary->allVariables.push_back(variable);
				}
			}
			// Function body.
			std::vector<Statement*> statements = scanStatements(fetchStatementsJson(functionJson["children"][2]));
			programSummary->functions.back().statements.insert
			(
				programSummary->functions.back().statements.end(),
				statements.begin(),
				statements.end()
			);

			currentFunctionName = "";
		}

		// Check if main function exists.
		bool mainFunctionExists = false;
		for (std::string functionName : allFunctionNames)
		{
			if (functionName == "main")
				mainFunctionExists = true;
		}
		if (!mainFunctionExists)
			printError("No main function.");
	}
	else
	{
		printError("Can not find function definition.");
	}

	return programSummary;
}

std::vector<Statement*> CodeScanner::scanStatements(std::vector<nlohmann::json> statementsJson)
{
	pushNewScope();
	std::vector<Statement*> statements;

	// Actions for every type of statement.
	for (auto statementJson : statementsJson)
	{
		const std::string statementName = toString(statementJson["name"]);
		if (statementName == "DeclarationStatement")
		{
			for (auto declaratorJson : statementJson["children"][1]["children"])
			{
				Identifier* variable = new Identifier
				(
					toDataType(statementJson["children"][0]["value"]),
					toString(declaratorJson["value"]),
					getGlobalId()
				);

				if (declaratorJson["name"] == "DeclaratorWithValue")
				{
					statements.push_back(new AssignmentStatement
					(
						variable,
						"=",
						scanExpression(declaratorJson["children"][0])
					));
				}
				else
				{
					statements.push_back(new EmptyStatement());
				}

				scopeStack.back().localVariables.insert(variable);
			}
		}
		else if (statementName == "AssignmentStatement")
		{
			statements.push_back(new AssignmentStatement
			(
				findVariable(toString(statementJson["children"][0]["value"])),
				toString(statementJson["children"][1]["value"]),
				scanExpression(statementJson["children"][2])
			));
		}
		else if (statementName == "IfStatement")
		{
			statements.push_back(new IfStatement
			(
				scanExpression(statementJson["children"][0]),
				scanStatements(fetchStatementsJson(statementJson["children"][1]))
			));
		}
		else if (statementName == "IfElseStatement")
		{
			statements.push_back(new IfStatement
			(
				scanExpression(statementJson["children"][0]),
				scanStatements(fetchStatementsJson(statementJson["children"][1])),
				scanStatements(fetchStatementsJson(statementJson["children"][2]))
			));
		}
		else if (statementName == "WhileStatement")
		{
			statements.push_back(new WhileStatement
			(
				scanExpression(statementJson["children"][0]),
				scanStatements(fetchStatementsJson(statementJson["children"][1]))
			));
		}
		else if (statementName == "DoWhileStatement")
		{
			statements.push_back(new DoWhileStatement
			(
				scanStatements(fetchStatementsJson(statementJson["children"][0])),
				scanExpression(statementJson["children"][1])
			));
		}
		else if (statementName == "ForStatement")
		{
			// Combine statements.
			std::vector<nlohmann::json> combinedStatementsJson;
			combinedStatementsJson.push_back(statementJson["children"][0]);
			combinedStatementsJson.push_back(statementJson["children"][1]);
			for (auto statementJson : fetchStatementsJson(statementJson["children"][3]))
			{
				combinedStatementsJson.push_back(statementJson);
			}
			combinedStatementsJson.push_back(statementJson["children"][2]);

			statements.push_back(new ForStatement(
				scanStatements(combinedStatementsJson)
			));
		}
		else if (statementName == "JumpStatement")
		{
			const std::string jumpStatementName = toString(statementJson["value"]);
			if (jumpStatementName == "return")
			{
				if (statementJson["children"] != nullptr)
				{
					statements.push_back(new JumpStatement(
						JumpStatement::RETURN,
						scanExpression(statementJson["children"][0])
					));
				}
				else
				{
					statements.push_back(new JumpStatement(JumpStatement::RETURN));
				}
			}
			else if (jumpStatementName == "break")
			{
				statements.push_back(new JumpStatement(JumpStatement::BREAK));
			}
			else if (jumpStatementName == "continue")
			{
				statements.push_back(new JumpStatement(JumpStatement::CONTINUE));
			}
			else
			{
				printError("Unknown JumpStatement value: " + jumpStatementName);
			}
		}
		else if (statementName == "ExpressionStatement")
		{
			statements.push_back(new ExpressionStatement
			(
				scanExpression(statementJson["children"][0])
			));
		}
		else
		{
			printError("Unknown statement name: " + statementName);
		}
	}
	
	popScope();
	return statements;
}

Expression* CodeScanner::scanExpression(nlohmann::json expressionJson, bool isRoot)
{
	Expression* returnExpre = NULL;
	const std::string expressionName = toString(expressionJson["name"]);
	if (expressionName == "LogicalExpression")
	{
		returnExpre = new TwoExpreExpression
		(
			scanExpression(expressionJson["children"][0], false),
			scanExpression(expressionJson["children"][1], false),
			toString(expressionJson["value"]),
			TwoExpreExpression::LOGICAL
		);
	}
	else if (expressionName == "RelationalExpression")
	{
		returnExpre = new TwoExpreExpression
		(
			scanExpression(expressionJson["children"][0], false),
			scanExpression(expressionJson["children"][1], false),
			toString(expressionJson["value"]),
			TwoExpreExpression::RELATIONAL
		);
	}
	else if (expressionName == "ArithmeticExpression")
	{
		returnExpre = new TwoExpreExpression
		(
			scanExpression(expressionJson["children"][0], false),
			scanExpression(expressionJson["children"][1], false),
			toString(expressionJson["value"]),
			TwoExpreExpression::ARITHMETIC
		);
	}
	else if (expressionName == "PrefixExpression")
	{
		std::string oper = toString(expressionJson["value"]);
		if (oper == "&")
		{
			returnExpre = scanExpression(expressionJson["children"][0], false);
		}
		else
		{
			returnExpre = new OneExpreExpression
			(
				scanExpression(expressionJson["children"][0], false),
				toString(expressionJson["value"]),
				OneExpreExpression::PREFIX
			);
		}
	}
	else if (expressionName == "PostfixExpression")
	{
		returnExpre = new OneExpreExpression
		(
			scanExpression(expressionJson["children"][0], false),
			toString(expressionJson["value"]),
			OneExpreExpression::POSTFIX
		);
	}
	else if (expressionName == "Identifier")
	{
		returnExpre = new ConstantExpression(findVariable(toString(expressionJson["value"])));
	}
	else if (expressionName == "ConstantNumber")
	{
		returnExpre = new ConstantExpression(getConstant(toString(expressionJson["value"]), Constant::NUM));
	}
	else if (expressionName == "ConstantString")
	{
		returnExpre = new ConstantExpression(getConstant(toString(expressionJson["value"]), Constant::STR));
	}
	else if (expressionName == "FunctionCall")
	{
		const std::string functionName = toString(expressionJson["value"]);
		if (isReservedFunction(functionName))
		{
			ReservedFunctionExpression* exprePtr = new ReservedFunctionExpression(functionName == "printf"? ReservedFunctionExpression::PRINTF : ReservedFunctionExpression::SCANF);
			if (expressionJson["children"][0]["children"] != nullptr)
			{
				std::string str = toString(expressionJson["children"][0]["children"][0]["children"][0]["value"]);
				str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
				
				size_t delimeterIndex = str.find("%");
				while (delimeterIndex != std::string::npos)
				{
					if(delimeterIndex != 0)
						exprePtr->constantStrings.push_back(new ConstantExpression(getConstant(str.substr(0, delimeterIndex), Constant::STR)));
					exprePtr->constantStrings.push_back(new ConstantExpression(getConstant(str.substr(delimeterIndex, 2), Constant::STR)));
					str = str.substr(delimeterIndex + 2);
					delimeterIndex = str.find("%");
				}
				if (!str.empty())
				{
					exprePtr->constantStrings.push_back(new ConstantExpression(getConstant(str, Constant::STR)));
				}

				std::vector<nlohmann::json> argumentsJson = expressionJson["children"][0]["children"];
				for (auto argumentJson : std::vector<nlohmann::json>({ argumentsJson.begin() + 1, argumentsJson.end() }))
				{
					exprePtr->arguments.push_back(scanExpression(argumentJson["children"][0], false));
				}
			}
			else
			{
				printError("Function call " + functionName + " with no argument.");
			}
			returnExpre = exprePtr;
		}
		else if (findFunction(functionName) != NULL)
		{
			FunctionCallExpression* exprePtr = new FunctionCallExpression(functionName, findFunction(functionName)->returnDataType != DataType::VOID);
			if (expressionJson["children"][0]["children"] != nullptr)
			{
				for (auto argumentJson : expressionJson["children"][0]["children"])
				{
					exprePtr->arguments.push_back(scanExpression(argumentJson["children"][0], false));
				}
			}
			if (findFunction(functionName)->parameters.size() != exprePtr->arguments.size())
			{
				printError("Number of arguments of " + functionName + " doesn't match.");
			}
			returnExpre = exprePtr;
		}
	}
	else
	{
		printError("Unknown expression name: " + expressionName);
	}

	if (isRoot)
		programSummary->allExpressions.push_back(returnExpre);

	return returnExpre;
}

Constant* CodeScanner::getConstant(std::string value, Constant::Type type)
{
	for (Constant* constant : programSummary->allConstants)
	{
		if (constant->type == type && constant->value == value)
			return constant;
	}

	Constant* newConstant = new Constant(value, type, std::to_string(programSummary->allConstants.size()));
	programSummary->allConstants.push_back(newConstant);
	return newConstant;
}

std::vector<nlohmann::json> CodeScanner::fetchStatementsJson(nlohmann::json jsonData)
{
	if (toString(jsonData["name"]).find("Statement") == std::string::npos)
		return {};

	if (jsonData["name"] == "CompoundStatement")
		if (jsonData["children"][0]["children"] != nullptr)
			return jsonData["children"][0]["children"];
		else
			return {};

	// A purely single statement.
	return { jsonData };
}

Identifier* CodeScanner::findVariable(std::string name)
{
	// For every level of scope from bottom to top.
	for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); it++)
	{
		for (Identifier* variable : it->localVariables)
		{
			if (variable->name == name)
				return variable;
		}
	}
	// Check function parameters.
	for (Identifier* variable : findFunction(globalId.functionName)->parameters)
	{
		if (variable->name == name)
			return variable;
	}

	printError("Can not find the variable \"" + name + "\"");
	return NULL;
}

Function* CodeScanner::findFunction(std::string name)
{
	for (size_t i = 0; i < programSummary->functions.size(); i++)
	{
		if (programSummary->functions[i].name == name)
			return &(programSummary->functions[i]);
	}

	printError("Can not find the function " + name);
	return NULL;
}

bool CodeScanner::isReservedFunction(std::string name)
{
	if (name == "printf")
	{
		programSummary->hasPrintf = true;
		return true;
	}
	if (name == "scanf")
	{
		programSummary->hasScanf = true;
		return true;
	}
	return false;
}

inline std::string CodeScanner::toString(nlohmann::json jsonData)
{
	return jsonData.template get<std::string>();
}

DataType CodeScanner::toDataType(nlohmann::json jsonData)
{
	if (jsonData == "void")
		return DataType::VOID;
	if (jsonData == "int")
		return DataType::INT;
	if (jsonData == "float")
		return DataType::FLOAT;
}

void CodeScanner::pushNewScope()
{
	if (globalId.functionName.empty())
	{
		globalId.functionName = programSummary->functions.back().name;
	}
	else if (getGlobalId() == lastPoppedScope.level)
	{
		globalId.scopeIdStack.push_back(lastPoppedScope.id + 1);
	}
	else
	{
		globalId.scopeIdStack.push_back(0);
	}

	scopeStack.push_back(Scope());
}

void CodeScanner::popScope()
{
	// Handle scopeId.
	std::string scopeId = getGlobalId();
	if (globalId.scopeIdStack.size() == 0)
	{
		globalId.functionName = "";

		lastPoppedScope.level = "";
		lastPoppedScope.id = -1;
	}
	else
	{
		globalId.scopeIdStack.pop_back();

		const size_t lastUnderlineIndex = scopeId.find_last_of("_");
		lastPoppedScope.level = scopeId.substr(0, lastUnderlineIndex);
		lastPoppedScope.id = std::stoi(scopeId.substr(lastUnderlineIndex + 1));
	}

	// Gather all local variables.
	Scope lastScope = scopeStack.back();
	programSummary->allVariables.insert
	(
		programSummary->allVariables.end(),
		lastScope.localVariables.begin(), 
		lastScope.localVariables.end()
	);

	scopeStack.pop_back();
}

std::string CodeScanner::getGlobalId()
{
	std::string id = globalId.functionName;
	for (int segmentId : globalId.scopeIdStack)
	{
		id += std::string("_") + std::to_string(segmentId);
	}
	return id;
}

void CodeScanner::printError(std::string errorMessage)
{
	std::cerr << "Error: " << errorMessage << std::endl;
	programSummary->hasError = true;
}