#pragma once
#include <string>
#include <iostream>
#include "Mediator.h"



class Person
{
public:
	Person(Mediator* pMediator, const std::string& strName) : m_pMediator(pMediator), m_strName(strName) { }
	virtual ~Person() {}

	virtual void SendMessage(const std::string& strMessage) = 0;
	virtual void GetMessage(const std::string& strMessage) = 0;

	enum  PersonType
	{
		Type_Renter,
		Type_LandLord
	};
	virtual PersonType GetType() = 0;

protected:
	Mediator* m_pMediator;
	std::string m_strName;
};

class Renter : public Person
{
public:
	Renter(Mediator* pMediator, const std::string& strName) : Person(pMediator, strName) {
		pMediator->AddRenter(this);
	}

	virtual void SendMessage(const std::string& strMessage)
	{
		std::cout << "租客" << m_strName << "发送消息: " << strMessage << std::endl;
		m_pMediator->Send(this, strMessage);
	}

	virtual void GetMessage(const std::string& strMessage)
	{
		std::cout << "租客" << m_strName << "收到消息: " << strMessage << std::endl;
	}

	virtual PersonType GetType()
	{
		return Type_Renter;
	}
};

class Landlord : public Person
{
public:
	Landlord(Mediator* pMediator, const std::string& strName) : Person(pMediator, strName) {
		pMediator->AddLandlord(this);
	}

	virtual void SendMessage(const std::string& strMessage)
	{
		std::cout << "房东" << m_strName << "发送消息: " << strMessage << std::endl;
		m_pMediator->Send(this, strMessage);
	}

	virtual void GetMessage(const std::string& strMessage)
	{
		std::cout << "房东" << m_strName << "收到消息: " << strMessage << std::endl;
	}

	virtual PersonType GetType()
	{
		return Type_LandLord;
	}
};