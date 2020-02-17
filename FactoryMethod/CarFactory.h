#pragma once
#include "CarProduct.h"

class CarFactory
{
public:
	virtual CarProduct* CreateCar() = 0;
	virtual ~CarFactory(void) {};
};

class CarAudiFactory : public CarFactory
{
public:
	virtual CarProduct* CreateCar()
	{
		return new CarAudi();
	}
};

class CarBenzFactory : public CarFactory
{
public:
	virtual CarProduct* CreateCar()
	{
		return new CarBenz();
	}
};

class CarBmwFactory : public CarFactory
{
public:
	virtual CarProduct* CreateCar()
	{
		return new CarBmw();
	}
};