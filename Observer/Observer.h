#pragma once

class Subject;
class Observer
{
public:
	virtual void Update(Subject* pSubject) = 0;
	virtual ~Observer(void) {};
};

