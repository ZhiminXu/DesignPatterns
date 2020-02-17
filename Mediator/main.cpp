#include "Person.h"
#include "Mediator.h"

void main()
{
	Mediator* pMediator = new HouseMediator();
	Person* pPerson1 = new Renter(pMediator, "张三");
	Person* pPerson2 = new Renter(pMediator, "李四");
	Person* pPerson3 = new Renter(pMediator, "王五");

	Person* pPerson4 = new Landlord(pMediator, "张姐");
	Person* pPerson5 = new Landlord(pMediator, "陈姐");

	pPerson1->SendMessage("需求：两室一厅");
	pPerson4->SendMessage("出租：三室一厅");

	delete pPerson1; pPerson1 = nullptr;
	delete pPerson2; pPerson2 = nullptr;
	delete pPerson3; pPerson3 = nullptr;
	delete pPerson4; pPerson4 = nullptr;
	delete pPerson5; pPerson5 = nullptr;
}