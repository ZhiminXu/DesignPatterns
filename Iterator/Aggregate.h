#pragma once
#include <vector>
#include "Iterator.h"

template <typename T>
class Aggregate
{
public:
	virtual ~Aggregate() {}
	virtual Iterator<T>* CreateIterator() = 0;
	virtual void Push(T* t) = 0;
	virtual T* Pop(const int nIndex) = 0;
	virtual int Size() = 0;
};