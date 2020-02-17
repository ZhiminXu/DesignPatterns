#pragma once
#include <string>
#include <stack>
#include "Expression.h"

class Analyzer
{
public:
	Expression* Analyse(std::string strExpression)
	{
		std::stack<Expression*> stack;
		Expression* left = nullptr;
		Expression* right = nullptr;
		for (size_t i = 0; i < strExpression.size(); i++)
		{
			switch (strExpression[i])
			{
			case '+':
				left = stack.top();
				right = new VarExpression(strExpression[++i]);
				stack.push(new AddExpression(left, right));
				break;
			case '-':
				left = stack.top();
				right = new VarExpression(strExpression[++i]);
				stack.push(new SubExpression(left, right));
				break;
			default:
				stack.push(new VarExpression(strExpression[i]));
				break;
			}
		}
		return stack.top();
	}
};

