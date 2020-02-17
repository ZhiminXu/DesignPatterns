#pragma once
#include <iostream>
#include <mutex>
#include <atomic>

//针对多线程双检查锁实现，但是内存读写reorder不安全

class Singleton3
{
public:
	/*
	当线程1进入21行
	正常程序执行过程为：分配内存——构造对象——地址赋值；
	但编译器优化后可能：分配内存——地址赋值——构造对象；
	这时，可能在地址赋值后但未构造对象前，另一个线程进来19行singleton不为空而直接返回，但实际上对象此时不能用
	*/
	static Singleton3* Instance()
	{
		if (nullptr == singleton)
		{
			std::lock_guard<std::mutex> lock(mutex);
			if (nullptr == singleton)
			{
				singleton = new Singleton3();
			}
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
	Singleton3() {}
	Singleton3(const Singleton3& obj) {}
	Singleton3& operator=(const Singleton3& obj) {}
	static Singleton3* singleton;
	static std::mutex mutex;
};

Singleton3* Singleton3::singleton = nullptr;
std::mutex Singleton3::mutex;