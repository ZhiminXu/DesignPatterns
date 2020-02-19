#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Subject.h"
#include "Observer.h"


class ConsoleObserver : public Observer
{
public:
	virtual void Update(Subject* pSubject)
	{
		std::cout << pSubject->GetLog() << std::endl;
	}
};

class LogObserver : public Observer
{
public:
	LogObserver(std::string strFile) {
		m_logger.open(strFile);
	}

	virtual void Update(Subject* pSubject)
	{
		m_logger << pSubject->GetLog() << std::endl;
	}

	~LogObserver()
	{
		m_logger.close();
	}

private:
	std::ofstream m_logger;
};


class Task : public Subject
{
public:
	void Run()
	{
		for (int i = 0; i < 4; i++)
		{
			std::stringstream ss;	
			ss << "handling " << i + 1 << " of 4";
			
			SetLog(ss.str());
		}
	}

	virtual std::string GetLog()
	{
		return m_strLog;
	}

	virtual void SetLog(std::string strLog)
	{
		m_strLog = strLog;
		Notify();
	}
private:
	std::string m_strLog;

};

void main()
{
	Task task;

	ConsoleObserver co;
	LogObserver lo("1.txt");

	task.addObserver(&co);
	task.addObserver(&lo);

	task.Run();
}