#include "Mediator.h"

#include "Person.h"


HouseMediator::~HouseMediator()
{
	auto iter1 = pListRenter.begin();
	while (iter1 != pListRenter.end()) {
		delete* iter1;
		*iter1 = nullptr;
		iter1++;
	}
	pListRenter.clear();

	auto iter2 = pListLandlord.begin();
	while (iter2 != pListLandlord.end()) {
		delete* iter2;
		*iter2 = nullptr;
		iter2++;
	}
	pListLandlord.clear();
}

void HouseMediator::AddRenter(Person* renter)
{
	if (nullptr != renter)
		pListRenter.push_back(renter);
}

void HouseMediator::AddLandlord(Person* landlord)
{
	if (nullptr != landlord)
		pListLandlord.push_back(landlord);
}

void HouseMediator::Send(Person* personFrom, const std::string& message)
{
	if (Person::Type_Renter == personFrom->GetType())
	{
		auto iter = pListLandlord.begin();
		while (iter != pListLandlord.end()) {
			(*iter)->GetMessage(message);
			iter++;
		}
	}
	else
	{
		auto iter = pListRenter.begin();
		while (iter != pListRenter.end()) {
			(*iter)->GetMessage(message);
			iter++;
		}
	}
}
