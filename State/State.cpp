#include "State.h"

StandState* StandState::pStandState = new StandState();
SquatState* SquatState::pSquateState = new SquatState();
LieProneState* LieProneState::pLieProneState = new LieProneState();

StandState::AutoDeletor StandState::autoDeletor;
SquatState::AutoDeletor SquatState::autoDeletor;
LieProneState::AutoDeletor LieProneState::autoDeletor;


void StandState::Down(Person* person)
{
	person->SetState(SquatState::Instance());
}

void SquatState::Down(Person* person)
{
	person->SetState(LieProneState::Instance());
}

void SquatState::Up(Person* person)
{
	person->SetState(StandState::Instance());
}

void LieProneState::Up(Person* person)
{
	person->SetState(SquatState::Instance());
}
