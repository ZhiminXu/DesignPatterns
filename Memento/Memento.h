#pragma once
#include <string>

typedef std::string State;

class Memento
{
public:
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

