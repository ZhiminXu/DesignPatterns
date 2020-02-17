#include <iostream>
#include <sstream>
#include <fstream>

#include "Subject.h"
#include "Observer.h"


class ConsoleObserver : public Observer
{
public:
	virtual void Update(std::string strMessage)
	{
		std::cout << strMessage <<std::endl;
	}
};

class LogObserver : public Observer
{
public:
	LogObserver(std::string strFile) {
		m_logger.open(strFile);
	}

	virtual void Update(std::string strMessage)
	{
		m_logger << strMessage << std::endl;
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
			Notify(ss.str());
		}
	}
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