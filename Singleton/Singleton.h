#pragma once
#include <iostream>

//饿汉模式，线程安全

class Singleton
{
public:
	static Singleton* Instance()
	{
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
	Singleton() {}
	Singleton(const Singleton& obj) {}
	Singleton& operator=(const Singleton& obj) {}
	static Singleton* singleton;
	
};

Singleton* Singleton::singleton =  new Singleton();