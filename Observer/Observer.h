#pragma once

class Observer
{
public:
	virtual void Update(std::string strMessage) = 0;
	virtual ~Observer(void) {};
};

