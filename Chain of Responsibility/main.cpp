#include "Request.h"
#include "Handler.h"

void main()
{
	Handler* pBoss = new Boss(nullptr);
	Handler* pManager = new Manager(pBoss);
	Handler* pHeadman = new Headman(pManager);

	Request* pRequest1 = new Request("申请事假", RequestLevel::Request_Level3);
	Request* pRequest2 = new Request("申请加薪", RequestLevel::Request_Level2);
	Request* pRequest3 = new Request("要求升职", RequestLevel::Request_Level1);

	pHeadman->Handle(pRequest1);
	pHeadman->Handle(pRequest2);
	pHeadman->Handle(pRequest3);

	delete pBoss; pBoss = nullptr;
	delete pManager; pManager = nullptr;
	delete pHeadman; pHeadman = nullptr;
	delete pRequest1; pRequest1 = nullptr;
	delete pRequest2; pRequest2 = nullptr;
	delete pRequest3; pRequest3 = nullptr;
	std::cin.get();
}