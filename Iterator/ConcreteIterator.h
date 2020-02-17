#pragma once
#include "Iterator.h"
#include "Aggregate.h"

template <typename T>
class ConcreteIterator : public Iterator<T>
{
public:
	ConcreteIterator(Aggregate<T>* pAggregate) : m_pAggregate(pAggregate), m_nCurr(0) {}
	virtual void First()
	{
		m_nCurr = 0;
	}

	virtual void Next()
	{
		if (m_nCurr < m_pAggregate->Size())
			m_nCurr++;
	}
	virtual bool IsDone()
	{
		return m_nCurr >= m_pAggregate->Size();
	}
	virtual T* CurrentItem()
	{
		T* t(nullptr);
		if (m_nCurr < m_pAggregate->Size())
			t = m_pAggregate->Pop(m_nCurr);
		return t;
	}
private:
	Aggregate<T>* m_pAggregate;
	int m_nCurr;
};
