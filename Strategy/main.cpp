#include "Sales.h"
#include <iostream>

void main()
{
	SalesDiscount* pDiscount = new VIPDiscount();
	
	SalesOrder order;
	order.SetDiscount(pDiscount);

	std::cout << order.Calculate(200.0) << std::endl;

	delete pDiscount; pDiscount = nullptr;
}