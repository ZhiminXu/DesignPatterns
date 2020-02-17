#pragma once
#include <iostream>
#include <mutex>
#include <atomic>

//针对多线程适用，基于C++11特性

class Singleton4
{
public:
	static Singleton4* Instance()
	{
		Singleton4* tmp = singleton.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);
		if (nullptr == singleton)
		{
			std::lock_guard<std::mutex> lock(mutex);
			tmp = singleton.load(std::memory_order_relaxed);
			if (nullptr == singleton)
			{
				tmp = new Singleton4();
				std::atomic_thread_fence(std::memory_order_release);
				singleton.store(tmp, std::memory_order_relaxed);
			}
		}
		return tmp;
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
	Singleton4() {}
	Singleton4(const Singleton4& obj) {}
	Singleton4& operator=(const Singleton4& obj) {}
	static std::atomic<Singleton4*> singleton;
	static std::mutex mutex;
};

std::atomic<Singleton4*> Singleton4::singleton;
std::mutex Singleton4::mutex;