#ifndef PROGRAMSUMMARY_H
#define PROGRAMSUMMARY_H

#include <vector>
#include <iostream>
#include <set>

enum DataType
{
	VOID,
	INT,
	FLOAT,
};

// Base strucutre.
struct Expression
{
	virtual void free() = 0;
};

struct Identifier
{
	DataType dataType;
	std::string name;
	std::string globalId;
	Expression* initialValue;

	Identifier(DataType d, std::string n, std::string id) 
	{
		dataType = d;
		name = n;
		globalId = id + "_" + n;
		initialValue = NULL;
	}
};

struct Constant 
{
	std::string value;
	enum Type
	{
		NUM,
		STR
	} type;
	std::string globalId;
	Constant(std::string v, Type t, std::string id)
	{
		value = v;
		type = t;
		globalId = "_constant" + id;
	}
};

struct TwoExpreExpression : Expression
{
	Expression* expre1;
	Expression* expre2;
	std::string expreOperator;
	enum Type
	{
		LOGICAL,
		RELATIONAL,
		ARITHMETIC
	} type;

	static inline const char* getTypeName()
	{
		return typeid(TwoExpreExpression).name();
	}
	TwoExpreExpression(Expression* e1, Expression* e2, std::string oper, Type t)
	{
		expre1 = e1;
		expre2 = e2;
		expreOperator = oper;
		type = t;
	}
	void free() override
	{
		if (expre1 != NULL)
		{
			expre1->free();
			delete expre1;
			expre1 = NULL;
		}
		if (expre2 != NULL)
		{
			expre2->free();
			delete expre2;
			expre2 = NULL;
		}
	}
};

struct OneExpreExpression : Expression
{
	Expression* expression;
	std::string expreOperator;
	enum Type
	{
		PREFIX,
		POSTFIX,
	} type;

	static inline const char* getTypeName()
	{
		return typeid(OneExpreExpression).name();
	}
	OneExpreExpression(Expression* e, std::string oper, Type t)
	{
		expression = e;
		expreOperator = oper;
		type = t;
	}
	void free() override
	{
		if (expression != NULL)
		{
			expression->free();
			delete expression;
			expression = NULL;
		}
	}
};

struct ConstantExpression : Expression
{
	Identifier* variable;
	Constant* constant;
	enum Type
	{
		ID,
		CONST
	} type;

	static inline const char* getTypeName() 
	{ 
		return typeid(ConstantExpression).name(); 
	}
	ConstantExpression(Identifier* id)
	{
		variable = id;
		constant = NULL;
		type = Type::ID;
	}
	ConstantExpression(Constant* c)
	{
		variable = NULL;
		constant = c;
		type = Type::CONST;
	}
	void free() override
	{
		// Do nothing.
	}
};

struct FunctionCallExpression : Expression
{
	std::string functionName;
	std::vector<Expression*> arguments;
	bool hasReturnValue;

	static inline const char* getTypeName()
	{
		return typeid(FunctionCallExpression).name();
	}
	FunctionCallExpression(std::string funcName, bool hasRetVal)
	{
		functionName = funcName;
		hasReturnValue = hasRetVal;
	}
	void free() override
	{
		for (Expression* expre : arguments)
		{
			if (expre != NULL)
			{
				expre->free();
				delete expre;
				expre = NULL;
			}
		}
		arguments.clear();
	}
};

struct ReservedFunctionExpression : Expression
{
	std::vector<Expression*> constantStrings;
	std::vector<Expression*> arguments;
	enum Type
	{
		PRINTF,
		SCANF
	} type;

	static inline const char* getTypeName()
	{
		return typeid(ReservedFunctionExpression).name();
	}
	ReservedFunctionExpression(Type t)
	{
		type = t;
	}
	void free() override
	{
		for (Expression* expre : constantStrings)
		{
			if (expre != NULL)
			{
				expre->free();
				delete expre;
				expre = NULL;
			}
		}
		constantStrings.clear();

		for (Expression* expre : arguments)
		{
			if (expre != NULL)
			{
				expre->free();
				delete expre;
				expre = NULL;
			}
		}
		arguments.clear();
	}
};

// Empty base structure.
struct Statement 
{
	virtual void free() = 0;
};

struct AssignmentStatement : Statement
{
	Identifier* variable;
	std::string assignmentOperator;
	Expression* expression;

	static inline const char* getTypeName()
	{
		return typeid(AssignmentStatement).name();
	}
	AssignmentStatement(Identifier* i, std::string a, Expression* e)
	{
		variable = i;
		assignmentOperator = a;
		expression = e;
	}
	void free() override
	{
		// Do nothing.
	}
};

struct IfStatement : Statement
{
	Expression* expression;
	std::vector<Statement*> trueStatements;
	std::vector<Statement*> elseStatements;

	static inline const char* getTypeName()
	{
		return typeid(IfStatement).name();
	}
	IfStatement(Expression* e, std::vector<Statement*> s1, std::vector<Statement*> s2 = {})
	{
		expression = e;
		trueStatements = s1;
		elseStatements = s2;
	}
	void free() override
	{
		for (Statement* statement : trueStatements)
		{
			if (statement != NULL)
			{
				statement->free();
				delete statement;
			}
		}
		trueStatements.clear();

		for (Statement* statement : elseStatements)
		{
			if (statement != NULL)
			{
				statement->free();
				delete statement;
			}
		}
		elseStatements.clear();
	}
};

struct WhileStatement : Statement
{
	Expression* expression;
	std::vector<Statement*> statements;

	static inline const char* getTypeName()
	{
		return typeid(WhileStatement).name();
	}
	WhileStatement(Expression* e, std::vector<Statement*> s)
	{
		expression = e;
		statements = s;
	}
	void free() override
	{
		for (Statement* statement : statements)
		{
			if (statement != NULL)
			{
				statement->free();
				delete statement;
			}
		}
		statements.clear();
	}
};

struct DoWhileStatement : Statement
{
	std::vector<Statement*> statements;
	Expression* expression;

	static inline const char* getTypeName()
	{
		return typeid(DoWhileStatement).name();
	}
	DoWhileStatement(std::vector<Statement*> s, Expression* e)
	{
		statements = s;
		expression = e;
	}
	void free() override
	{
		for (Statement* statement : statements)
		{
			if (statement != NULL)
			{
				statement->free();
				delete statement;
			}
		}
		statements.clear();
	}
};

struct ForStatement : Statement
{
	std::vector<Statement*> statements;

	static inline const char* getTypeName()
	{
		return typeid(ForStatement).name();
	}
	ForStatement(std::vector<Statement*> s)
	{
		statements = s;
	}
	void free() override
	{
		for (Statement* statement : statements)
		{
			if (statement != NULL)
			{
				statement->free();
				delete statement;
			}
		}
		statements.clear();
	}
};

struct JumpStatement : Statement
{
	enum Type
	{
		RETURN,
		BREAK,
		CONTINUE
	} type;
	Expression* returnExpre;

	static inline const char* getTypeName()
	{
		return typeid(JumpStatement).name();
	}
	JumpStatement(Type t)
	{
		type = t;
		returnExpre = NULL;
	}
	JumpStatement(Type t, Expression* e)
	{
		type = t;
		returnExpre = e;
	}
	void free() override
	{
		// Do nothing.
	}
};

struct ExpressionStatement : Statement
{
	Expression* expression;

	static inline const char* getTypeName()
	{
		return typeid(ExpressionStatement).name();
	}
	ExpressionStatement(Expression* e)
	{
		expression = e;
	}
	void free() override
	{
		// Do nothing.
	}
};

struct EmptyStatement : Statement
{
	static inline const char* getTypeName()
	{
		return typeid(EmptyStatement).name();
	}
	void free() override 
	{
		// Do nothing.
	}
};

struct Scope
{
	std::set<Identifier*> localVariables;
};

struct Function
{
	std::string name;
	DataType returnDataType;
	std::vector<Identifier*> parameters;
	std::vector<Statement*> statements;
	Function(std::string n, DataType type)
	{
		name = n;
		returnDataType = type;
	}
};

struct ProgramSummary
{
	bool hasError;
	bool hasPrintf;
	bool hasScanf;
	std::vector<Function> functions;
	std::vector<Identifier*> allVariables;
	std::vector<Constant*> allConstants;
	std::vector<Expression*> allExpressions;

	ProgramSummary()
	{
		hasError = false;
		hasPrintf = false;
		hasScanf = false;
	}
	void clear()
	{
		std::cout << "Number of functions: " << functions.size() << std::endl;
		hasError = false;
		functions.clear();

		for (Identifier* identifier : allVariables)
			delete identifier;
		std::cout << "Number of variables: " << allVariables.size() << std::endl;
		allVariables.clear();

		for (Constant* constant : allConstants)
			delete constant;
		std::cout << "Number of constants: " << allConstants.size() << std::endl;
		allConstants.clear();

		for (Expression* expression : allExpressions)
		{
			if (expression != NULL)
			{
				expression->free();
				delete expression;
			}
		}
		allExpressions.clear();

		for (Function function : functions)
		{
			for (Statement* statement : function.statements)
			{
				if (statement != NULL)
				{
					statement->free();
					delete statement;
				}
			}
			function.statements.clear();
		}
	}
};

#endif