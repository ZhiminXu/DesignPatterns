#pragma once
#include <iostream>

//针对单线程适用，多线程不安全

class Singleton1
{
public:
	static Singleton1* Instance()
	{
		if (nullptr == singleton)
		{
			singleton = new Singleton1();
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
	Singleton1() {}
	Singleton1(const Singleton1& obj) {}
	Singleton1& operator=(const Singleton1& obj) {}
	static Singleton1* singleton;
};

Singleton1* Singleton1::singleton = nullptr;





