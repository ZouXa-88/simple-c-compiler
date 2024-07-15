#ifndef CODESCANNER_H
#define CODESCANNER_H

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <set>
#include "program_summary.h"

class CodeScanner
{
public:
	~CodeScanner();
	const ProgramSummary* scan(nlohmann::json);

private:
	/*
		Attributes.
	*/
	ProgramSummary* programSummary;

	std::vector<Scope> scopeStack;
	struct GlobalId
	{
		std::string functionName;
		std::vector<int> scopeIdStack;
	} globalId;
	struct LastPoppedScope
	{
		std::string level;
		int id;
		LastPoppedScope() : level(""), id(-1) {}
	} lastPoppedScope;


	/*
		Methods.
	*/
	std::vector<Statement*> scanStatements(std::vector<nlohmann::json>);
	Expression* scanExpression(nlohmann::json, bool = true);
	Constant* getConstant(std::string, Constant::Type);

	std::vector<nlohmann::json> fetchStatementsJson(nlohmann::json);
	Identifier* findVariable(std::string);
	Function* findFunction(std::string);
	bool isReservedFunction(std::string);

	std::string toString(nlohmann::json);
	DataType toDataType(nlohmann::json);

	void pushNewScope();
	void popScope();
	std::string getGlobalId();

	void printError(std::string);
};

#endif