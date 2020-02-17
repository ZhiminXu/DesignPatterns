#pragma once

#include <iostream>

class Canvas
{
public:
	virtual void Draw() = 0;
	virtual ~Canvas(void) {};
};

class BlueCanvas : public Canvas
{
public:
	virtual void Draw()
	{
		std::cout << "blue canvas" <<std::endl;
	}
};

class RedCanvas : public Canvas
{
public:
	virtual void Draw()
	{
		std::cout << "red canvas" <<std::endl;
	}
};
