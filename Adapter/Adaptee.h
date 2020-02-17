#pragma once
#include <iostream>


class IAdaptee
{
public:
	virtual void SpecificRequest() = 0;
};

class OldClass : public IAdaptee
{
public:
	virtual void SpecificRequest()
	{
		std::cout << "specific request!" << std::endl;
	}
};

