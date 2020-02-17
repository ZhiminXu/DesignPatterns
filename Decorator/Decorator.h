#pragma once
#include "Canvas.h"

class Decorator : public Canvas
{
public:
	Decorator(Canvas* cvs) : m_canvas(cvs) {}
	
	virtual void Draw(){
		m_canvas->Draw();
	}

protected:
	Canvas* m_canvas;
};

class BorderCanvas : public Decorator
{
public:
	BorderCanvas(Canvas* cvs) : Decorator(cvs) {}
	virtual void Draw()
	{
		m_canvas->Draw();
		addedOperation();
	}

	void addedOperation()
	{
		std::cout << "with border" <<std::endl;
	}
};

class FrameCanvas : public Decorator
{
public:
	FrameCanvas(Canvas* cvs) : Decorator(cvs) {}
	virtual void Draw()
	{
		m_canvas->Draw();
		addedOperation();
	}

	void addedOperation()
	{
		std::cout << "with frame" <<std::endl;
	}
};

