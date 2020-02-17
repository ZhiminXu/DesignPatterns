#pragma once
#include "Element.h"

class Visitor
{
public:
	virtual void VisitElementA(ElementA* pElementA) = 0;
	virtual void VisitElementB(ElementB* pElementB) = 0;
	virtual ~Visitor() {}
};


class ConcreteVisitor : public Visitor
{
public:
	virtual void VisitElementA(ElementA* pElementA)
	{
		std::cout << "Added operation for ElementA" << std::endl;
		pElementA->OperationA();
	}
	virtual void VisitElementB(ElementB* pElementB)
	{
		std::cout << "Added operation for ElementB" << std::endl;
		pElementB->OperationB();
	}
};

