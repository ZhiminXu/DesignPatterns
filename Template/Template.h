#pragma once
#include <iostream>


class TemplateCookedRice
{
public:
	TemplateCookedRice(float amount) : m_fltRice(amount) {}
	virtual ~TemplateCookedRice() {}
	void Cooking()
	{
		AddRice();
		AddWater();
		TurnOnElectricCooker();
		SetElectricCookerMode();
		WaitForFood();
	}

protected:
	virtual void AddRice()
	{
		std::cout << "Rice added :"<< m_fltRice << std::endl;
	}
	virtual void AddWater() = 0;
	virtual void TurnOnElectricCooker()
	{
		std::cout << "Electric cooker turned on¡­¡­" << std::endl;
	}
	virtual void SetElectricCookerMode() = 0;
	virtual void WaitForFood()
	{
		std::cout << "Waiting for food¡­¡­" << std::endl;
	}
protected:
	float m_fltRice;
};


class SteamedRice : public TemplateCookedRice
{
public:
	SteamedRice(float amount) : TemplateCookedRice(amount) {}
protected:
	virtual void AddWater()
	{
		std::cout << "Water added amount:" << 2 * m_fltRice << std::endl;
	}
	virtual void SetElectricCookerMode()
	{
		std::cout << "Electric cooker set to steamed rice mode¡­¡­" << std::endl;
	}

};

class Porridge : public TemplateCookedRice
{
public:
	Porridge(float amount) : TemplateCookedRice(amount) {}
protected:
	virtual void AddWater()
	{
		std::cout << "Water added amount:" << 4 * m_fltRice << std::endl;
	}
	virtual void SetElectricCookerMode()
	{
		std::cout << "Electric cooker set to porridge mode¡­¡­" << std::endl;
	}
};

