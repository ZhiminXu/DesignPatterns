#pragma once
#include <iostream>

class Paint
{
public:
	virtual void Draw(void) = 0;
	virtual ~Paint(void) {};
};


class RedPaint : public Paint
{
public:
	virtual void Draw()
	{
		std::cout << "Color Red!" << std::endl;
	}
};

class BluePaint : public Paint
{
public:
	virtual void Draw()
	{
		std::cout << "Color Blue!" << std::endl;
	}
};

