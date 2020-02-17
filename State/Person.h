#pragma once

class State;

class Person
{
public:
	Person(State* pState) : m_pState(pState) {}

	virtual void OnKeyDown();
	virtual void OnKeyUp();
	
	void MoveOn();
	void SetState(State* pState);

private:
	State* m_pState;
};

