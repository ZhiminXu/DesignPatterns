#include "Proxy.h"
#include "SubjectImpl.h"

Proxy::Proxy()
{
	m_pSubject = new SubjectImpl();
}

void Proxy::Operation()
{
	m_pSubject->Operation();
}
