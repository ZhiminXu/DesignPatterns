#include "Proxy.h"
#include "Subject.h"


/*
SubjectImpl �����и��ӵĽṹ�����׷����仯��ֱ��ʹ�û�����������������ӱ���ʱ�䡣
ͨ��Proxy���м�Ӵ������������������������˱仯��
*/
void main()
{
	Subject* pSubject = new Proxy();
	pSubject->Operation();

	delete pSubject; pSubject = nullptr;
}