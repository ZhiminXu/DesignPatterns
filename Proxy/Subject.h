#pragma once
#include <iostream>
#include <map>
#include <string>

class Subject
{
public:
	virtual void Operation() = 0;
	virtual ~Subject() {}
};

