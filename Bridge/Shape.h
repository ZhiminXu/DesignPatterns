#pragma once
#include "Paint.h"

class Shape
{
public:
	Shape(Paint* pt) : m_pt(pt) {}
	
	virtual ~Shape(void) {};

	virtual void Show()
	{
		m_pt->Draw();
	}

private:
	Paint* m_pt;
};

class Rect : public Shape
{
public:
	Rect(Paint* pt) : Shape(pt) {}

	virtual void Show()
	{
		std::cout << "Rect: ";
		Shape::Show();
	}
};


class Circle : public Shape
{
public:
	Circle(Paint* pt) : Shape(pt) {}

	virtual void Show()
	{
		std::cout << "Circle: ";
		Shape::Show();
	}
};
