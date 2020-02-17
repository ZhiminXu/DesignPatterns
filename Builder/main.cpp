#include "HouseDirector.h"
#include "HouseBuilder.h"

void main()
{
	HouseBuilder* pHouseBuilder = new StoneHouseBuilder();
	HouseDirector* pHouseDirector = new HouseDirector(pHouseBuilder);

	House* pHouse = pHouseDirector->Construct();

	delete pHouse; pHouse = nullptr;
	delete pHouseDirector; pHouseDirector = nullptr;
	delete pHouseBuilder; pHouseBuilder = nullptr;
}