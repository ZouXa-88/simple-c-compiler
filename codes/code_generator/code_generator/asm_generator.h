#ifndef ASMGENERATOR_H
#define ASMGENERATOR_H

#include <string>
#include <fstream>
#include "program_summary.h"

class AsmGenerator
{
public:
	AsmGenerator();
	bool hasError();
	void generateCode(const ProgramSummary*);

private:
	std::ofstream asmFile;
	const std::string outName;
	const std::string tab;
	bool error;

	void writeVariableDeclaration(const std::vector<Identifier*>);
	void writeConstantDeclaration(const std::vector<Constant*>);
	void writePrintfFunction();
	void writeScanfFunction();
	void writeFunction(Function);
	void writeStatements(std::vector<Statement*>);
	void writeStatement(Statement*);
	void writeExpression(Expression*, const char*);

	void printError(std::string);

	template<typename T>
	const char* getTypeName(T*);
};

#endif