#include "State.h"
#include "Person.h"

void main()
{
	Person* person = new Person(StandState::Instance());
	person->MoveOn();

	person->OnKeyDown();
	person->MoveOn();

	person->OnKeyDown();
	person->MoveOn();

	delete person; person = nullptr;
}