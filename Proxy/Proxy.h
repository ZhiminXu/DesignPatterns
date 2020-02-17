#pragma once

#include "Subject.h"

class SubjectImpl;

class Proxy : public Subject
{
public:
	Proxy();
	virtual void Operation();
private:
	SubjectImpl* m_pSubject;
};


