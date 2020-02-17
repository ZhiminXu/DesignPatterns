#include <iostream>
#include "Analyzer.h"
#include "Expression.h"

void main()
{
	std::string strExpression = "a+b-c+d";
	std::map<char, int> var;
	var.insert(std::make_pair<char, int>('a', 5));
	var.insert(std::make_pair<char, int>('b', 3));
	var.insert(std::make_pair<char, int>('c', 1));
	var.insert(std::make_pair<char, int>('d', 9));

	Analyzer analyzer;
	Expression* pExpression = analyzer.Analyse(strExpression);
	std::cout << "Result: " << pExpression->Interpreter(var) << std::endl;
	delete pExpression;

	std::cin.get();
}