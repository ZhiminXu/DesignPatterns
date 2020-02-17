#pragma once
#include <string>

class CarProduct
{
public:
	virtual std::string CarName(void) = 0;
	virtual ~CarProduct(void) {};
};

class CarAudi : public CarProduct
{
public:
	virtual std::string CarName(void)
	{
		return "Audi";
	}
};

class CarBenz : public CarProduct
{
public:
	virtual std::string CarName(void)
	{
		return "Benz";
	}
};

class CarBmw : public CarProduct
{
public:
	virtual std::string CarName(void)
	{
		return "BMW";
	}
};