#pragma once
#include <list>

#include "Observer.h"

class Subject
{
public:
	
	virtual ~Subject(void) {};

	void addObserver(Observer* observer)
	{
		m_lstObserver.push_back(observer);
	}

	void removeObserver(Observer* observer)
	{
		m_lstObserver.remove(observer);
	}
	
	void Notify(std::string strMessage)
	{
		std::list<Observer*>::iterator iter = m_lstObserver.begin();
		while (iter != m_lstObserver.end())
		{
			(*iter)->Update(strMessage);
			iter++;
		}
	}

private:
	std::list<Observer*> m_lstObserver;
};

