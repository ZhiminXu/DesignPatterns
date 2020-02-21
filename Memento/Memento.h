#pragma once
#include <string>

typedef std::string State;

class Originator;
class Memento
{
	friend class Originator;
protected:
	Memento(State state) : mState(state) {}
	State GetState()
	{
		return mState;
	}

	void SetState(State state)
	{
		mState = state;
	}

private:
	State mState;
};

