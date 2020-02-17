#include "Memento.h"
#include "Originator.h"

void main()
{
	Originator* pOriginator = new Originator("Walking����");

	//����״̬���ݡ�
	Memento* pMemento = pOriginator->CreateMemento();

	//�ָ�����״̬
	pOriginator->SetMemento(pMemento);

	delete pOriginator; pOriginator = nullptr;
	delete pMemento; pMemento = nullptr;
}
