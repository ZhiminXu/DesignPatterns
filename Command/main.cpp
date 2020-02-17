#include "Command.h"
#include "Image.h"

void main()
{
	Image* pImage = new Image(400, 600);
	ImageProcessCommand ipc(pImage);
	ipc.Zooming(2.0);
	ipc.Zooming(2.0);
	pImage->Show();

	ipc.Undo();
	pImage->Show();
	ipc.Undo();
	pImage->Show();

	ipc.Redo();
	ipc.Redo();
	pImage->Show();

	delete pImage; pImage = nullptr;
}