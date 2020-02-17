#pragma once
#include "Memento.h"

class Originator
{
public:
	Originator(State state) : mState(state) {}
	void SetMemento(Memento* memento)
	{
		mState = memento->GetState();
	}
	Memento* CreateMemento()
	{
		return new Memento(mState);
	}

private:
	State mState;
};