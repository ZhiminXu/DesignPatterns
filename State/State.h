#pragma once
#include <iostream>
#include "Person.h"

class State
{
public:
	virtual void Down(Person* person) = 0;
	virtual void Up(Person* person) = 0;
	virtual void Action(Person* person) = 0;
};

class StandState : public State
{
public:
	virtual void Down(Person* person);

	virtual void Up(Person* person)
	{
	}

	virtual void Action(Person* person)
	{
		std::cout << "walking¡­¡­" << std::endl;
	}

	static StandState* Instance()
	{
		return pStandState;
	}

	class AutoDeletor
	{
	public:
		~AutoDeletor()
		{
			if (nullptr != pStandState)
			{
				delete pStandState;
				pStandState = nullptr;
			}
		}
	};
private:
	StandState() {}
	static StandState* pStandState;
	static AutoDeletor autoDeletor;
};

class SquatState : public State
{
public:
	virtual void Down(Person* person);
	virtual void Up(Person* person);

	virtual void Action(Person* person)
	{
		std::cout << "squatting¡­¡­" << std::endl;
	}

	static SquatState* Instance()
	{
		return pSquateState;
	}

	class AutoDeletor
	{
	public:
		~AutoDeletor()
		{
			if (nullptr != pSquateState)
			{
				delete pSquateState;
				pSquateState = nullptr;
			}
		}
	};
private:
	SquatState() {}
	static SquatState* pSquateState;
	static AutoDeletor autoDeletor;
};

class LieProneState : public State
{
public:
	virtual void Down(Person* person)
	{
	}

	virtual void Up(Person* person);


	virtual void Action(Person* person)
	{
		std::cout << "climbing¡­¡­" << std::endl;
	}

	static LieProneState* Instance()
	{
		return pLieProneState;
	}

	class AutoDeletor
	{
	public:
		~AutoDeletor()
		{
			if (nullptr != pLieProneState)
			{
				delete pLieProneState;
				pLieProneState = nullptr;
			}
		}
	};

private:
	LieProneState() {}
	static LieProneState* pLieProneState;
	static AutoDeletor autoDeletor;
};

