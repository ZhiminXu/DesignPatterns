#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"
#include <iostream>

void main()
{
	Aggregate<int>* pAggr = new ConcreteAggregate<int>();
	pAggr->Push(new int(1));
	pAggr->Push(new int(2));
	pAggr->Push(new int(3));

	Iterator<int>* pIter = pAggr->CreateIterator();
	for (pIter->First(); !pIter->IsDone(); pIter->Next())
	{
		std::cout << *(pIter->CurrentItem()) << std::endl;
	}

	delete pAggr; pAggr = nullptr;
	delete pIter; pIter = nullptr;
}