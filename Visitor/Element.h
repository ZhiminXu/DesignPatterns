#pragma once
#include <iostream>

class Visitor;
class Element
{
public:
	virtual void Accept(Visitor* pVisitor) = 0;
	virtual ~Element() {}
};

class ElementA : public Element
{
public:
	virtual void Accept(Visitor* pVisitor);

	void OperationA()
	{
		std::cout << "ElementA Operation" << std::endl;
 	}
};

class ElementB : public Element
{
public:
	virtual void Accept(Visitor* pVisitor);
	void OperationB()
	{
		std::cout << "ElementB Operation" << std::endl;
	}
};