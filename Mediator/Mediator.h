#pragma once
#include <string>
#include <list>

class Person;

class Mediator
{
public:
    virtual void Send(Person* personFrom, const std::string& message) = 0;
	virtual void AddRenter(Person* renter) = 0;
	virtual void AddLandlord(Person* landlord) = 0;

    virtual ~Mediator() {}
};

class HouseMediator :public Mediator
{
public:
	~HouseMediator();

	virtual void AddRenter(Person* renter);
	virtual void AddLandlord(Person* landlord);


	virtual void Send(Person* personFrom, const std::string& message);

private:
	std::list<Person*> pListRenter;
	std::list<Person*> pListLandlord;
};
