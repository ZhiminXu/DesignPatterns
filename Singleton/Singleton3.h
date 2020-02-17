#pragma once
#include <iostream>
#include <mutex>
#include <atomic>

//��Զ��߳�˫�����ʵ�֣������ڴ��дreorder����ȫ

class Singleton3
{
public:
	/*
	���߳�1����21��
	��������ִ�й���Ϊ�������ڴ桪��������󡪡���ַ��ֵ��
	���������Ż�����ܣ������ڴ桪����ַ��ֵ�����������
	��ʱ�������ڵ�ַ��ֵ��δ�������ǰ����һ���߳̽���19��singleton��Ϊ�ն�ֱ�ӷ��أ���ʵ���϶����ʱ������
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