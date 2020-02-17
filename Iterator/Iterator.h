#pragma once

template <typename T>
class Iterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual T* CurrentItem() = 0;
};