#include "Person.h"
#include "Mediator.h"

void main()
{
	Mediator* pMediator = new HouseMediator();
	Person* pPerson1 = new Renter(pMediator, "����");
	Person* pPerson2 = new Renter(pMediator, "����");
	Person* pPerson3 = new Renter(pMediator, "����");

	Person* pPerson4 = new Landlord(pMediator, "�Ž�");
	Person* pPerson5 = new Landlord(pMediator, "�½�");

	pPerson1->SendMessage("��������һ��");
	pPerson4->SendMessage("���⣺����һ��");

	delete pPerson1; pPerson1 = nullptr;
	delete pPerson2; pPerson2 = nullptr;
	delete pPerson3; pPerson3 = nullptr;
	delete pPerson4; pPerson4 = nullptr;
	delete pPerson5; pPerson5 = nullptr;
}