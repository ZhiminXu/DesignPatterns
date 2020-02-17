#pragma once
#include <iostream>
#include "House.h"

class HouseBuilder
{
public:
	virtual ~HouseBuilder(void) {};
public:
	virtual void BuildGround() = 0;
	virtual void BuildWall() = 0;
	virtual void BuildWindowAndDoor() = 0;
	virtual void BuildRoof() = 0;
	virtual House* GetResult() = 0;

private:
	House* m_pHouse;
};

class StoneHouseBuilder : public HouseBuilder
{
public:
	virtual void BuildGround()
	{
		std::cout << "build stone house goroud" << std::endl;
	}
	virtual void BuildWall()
	{
		std::cout << "build stone house wall" << std::endl;
	}
	virtual void BuildWindowAndDoor()
	{
		std::cout << "build stone house window and door" << std::endl;
	}
	virtual void BuildRoof()
	{
		std::cout << "build stone house roof" << std::endl;
	}
	virtual House* GetResult()
	{
		return new StoneHouse();
	}
};

