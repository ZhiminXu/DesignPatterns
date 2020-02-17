#pragma once
#include "Adaptee.h"

class ITarget
{
public:
	virtual void Request() = 0;
	virtual ~ITarget() {};
};

class Adapter : public ITarget
{
public:
	Adapter(IAdaptee* pAdaptee) : m_pAdaptee(pAdaptee)
	{}
	virtual void Request()
	{
		m_pAdaptee->SpecificRequest();
	}
private:
	IAdaptee* m_pAdaptee;
};