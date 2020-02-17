#pragma once
#include "Aggregate.h"
#include "ConcreteIterator.h"

template <typename T>
class ConcreteAggregate : public Aggregate<T>
{
public:
	~ConcreteAggregate()
	{
		for (auto iter : m_vecValue)
		{
			delete iter;
			iter = nullptr;
		}
		m_vecValue.clear();
	}
	virtual Iterator<T>* CreateIterator()
	{
		return new ConcreteIterator<T>(this);
	}
	virtual void Push(T* t)
	{
		m_vecValue.push_back(t);
	}
	virtual T* Pop(const int nIndex)
	{
		T* t(nullptr);
		if (nIndex < Size())
			t = m_vecValue[nIndex];
		return t;
	}
	virtual int Size()
	{
		return m_vecValue.size();
	}

public:
	std::vector<T*> m_vecValue;
};

