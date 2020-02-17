#pragma once
#include <iostream>
#include <mutex>

//针对多线程适用，但是存在性能问题

class Singleton2
{
public:
	static Singleton2* Instance()
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (nullptr == singleton)
		{
			singleton = new Singleton2();
		}
		return singleton;
	}

	static void DestoryInstance()
	{
		if (nullptr != singleton)
		{
			delete singleton;
			singleton = nullptr;
		}
	}

	void DoSomething()
	{
		std::cout << "something done!" << std::endl;
	}

private:
	Singleton2() {}
	Singleton2(const Singleton2& obj) {}
	Singleton2& operator=(const Singleton2& obj) {}
	static Singleton2* singleton;
	static std::mutex mutex;
};

Singleton2* Singleton2::singleton = nullptr;
std::mutex Singleton2::mutex;