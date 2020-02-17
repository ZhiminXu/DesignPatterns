#include "Visitor.h"
#include "Element.h"

void main()
{
	ElementA elementA;
	ConcreteVisitor visitor;
	elementA.Accept(&visitor);

	std::cin.get();
}