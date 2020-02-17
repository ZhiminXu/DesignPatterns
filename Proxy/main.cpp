#include "Proxy.h"
#include "Subject.h"


/*
SubjectImpl 包含有复杂的结构，极易发生变化；直接使用会引入过多依赖，增加编译时间。
通过Proxy进行间接代理，消除了这种依赖，隔离了变化。
*/
void main()
{
	Subject* pSubject = new Proxy();
	pSubject->Operation();

	delete pSubject; pSubject = nullptr;
}