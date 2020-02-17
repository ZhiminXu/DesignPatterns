#include "Paint.h"
#include "Shape.h"

void main()
{
	Paint* pt = new RedPaint();
	Shape* shp = new Circle(pt);

	shp->Show();

	delete pt; pt = nullptr;
	delete shp; shp = nullptr;
}