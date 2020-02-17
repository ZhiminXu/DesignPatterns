#pragma once
#include <map>

class Expression
{
public:
	virtual int Interpreter(std::map<char, int> var) = 0;
	virtual ~Expression() {}
};

class VarExpression : public Expression
{
public:
	VarExpression(const char& key) : mKey(key) {}
	virtual int Interpreter(std::map<char, int> var)
	{
		return var[mKey];
	}
private:
	char mKey;
};

class SymbolExpression : public Expression
{
public:
	SymbolExpression(Expression* left, Expression* right)
		: pExpressionLeft(left), pExpressionRight(right) {}
	~SymbolExpression()
	{
		delete pExpressionLeft; pExpressionLeft = nullptr;
		delete pExpressionRight; pExpressionRight = nullptr;
	}

	virtual int Interpreter(std::map<char, int> var) = 0;
protected:
	Expression* pExpressionLeft;
	Expression* pExpressionRight;
};

class AddExpression : public SymbolExpression
{
public:
	AddExpression(Expression* left, Expression* right)
		: SymbolExpression(left, right) {}
	virtual int Interpreter(std::map<char, int> var)
	{
		return pExpressionLeft->Interpreter(var) 
			+ pExpressionRight->Interpreter(var);
	}
};

class SubExpression : public SymbolExpression
{
public:
	SubExpression(Expression* left, Expression* right)
		: SymbolExpression(left, right) {}
	virtual int Interpreter(std::map<char, int> var)
	{
		return pExpressionLeft->Interpreter(var)
			- pExpressionRight->Interpreter(var);
	}
};
