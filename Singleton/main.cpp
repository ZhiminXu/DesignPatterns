#include "Singleton.h"

void main()
{
	Singleton::Instance()->DoSomething();
	Singleton::DestoryInstance();
}