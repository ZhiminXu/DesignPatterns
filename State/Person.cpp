#include "Person.h"
#include "State.h"

void Person::OnKeyDown()
{
	m_pState->Down(this);
}

void Person::OnKeyUp()
{
	m_pState->Up(this);
}

void Person::MoveOn()
{
	m_pState->Action(this);
}

void Person::SetState(State* pState)
{
	m_pState = pState;
}
