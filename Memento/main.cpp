#include "Memento.h"
#include "Originator.h"

void main()
{
	Originator* pOriginator = new Originator("Walking……");

	//创建状态备份。
	Memento* pMemento = pOriginator->CreateMemento();

	//恢复对象状态
	pOriginator->SetMemento(pMemento);

	delete pOriginator; pOriginator = nullptr;
	delete pMemento; pMemento = nullptr;
}
