#pragma once

class SalesDiscount
{
public:
	virtual ~SalesDiscount() {}
	virtual float Discount() = 0;
};

class NewConsumerDiscount : public SalesDiscount
{
public:
	virtual float Discount()
	{
		return 1.0;
	}
};

class OldConsumerDiscount : public SalesDiscount
{
public:
	virtual float Discount()
	{
		return 0.95;
	}
};

class VIPDiscount : public SalesDiscount
{
public:
	virtual float Discount()
	{
		return 0.85;
	}
};


class SalesOrder
{
public:
	void SetDiscount(SalesDiscount* pDiscount)
	{
		m_pDiscount = pDiscount;
	}
	float Calculate(float fltAmount)
	{
		return fltAmount * m_pDiscount->Discount();
	}
private:
	SalesDiscount* m_pDiscount;
};

