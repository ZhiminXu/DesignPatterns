#include "Canvas.h"
#include "Decorator.h"

/*
主体类n个， 如不同颜色的画布。BlueCanvas、RedCanvas
功能扩展m个，如对画布做不同形式的装饰。BorderDecorator、FrameDecorator

主体类与扩展类分支继承。

采用继承，总类数为，1+n+n*m
采用装饰模式，总类数为，1+n+1+m
*/

void main()
{
	Canvas* cvs = new RedCanvas();
	Decorator* dcr = new BorderCanvas(cvs);

	dcr->Draw();

	delete cvs; 
	cvs = nullptr;

	delete dcr; 
	dcr = nullptr;
}