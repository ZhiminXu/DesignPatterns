#include "Element.h"
#include "Visitor.h"

void ElementA::Accept(Visitor* pVisitor)
{
	pVisitor->VisitElementA(this);
}

void ElementB::Accept(Visitor* pVisitor)
{
	pVisitor->VisitElementB(this);
}
