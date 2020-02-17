#pragma once
#include "HouseBuilder.h"

class HouseDirector
{
public:
	HouseDirector(HouseBuilder* pHouseBuilder):m_pHouseBuilder(pHouseBuilder) {}
	virtual House* Construct()
	{
		m_pHouseBuilder->BuildGround();
		m_pHouseBuilder->BuildWall();
		m_pHouseBuilder->BuildWall();
		m_pHouseBuilder->BuildWall();
		m_pHouseBuilder->BuildWall();
		m_pHouseBuilder->BuildWindowAndDoor();
		m_pHouseBuilder->BuildRoof();

		return m_pHouseBuilder->GetResult();
	}
private:
	HouseBuilder* m_pHouseBuilder;
};

