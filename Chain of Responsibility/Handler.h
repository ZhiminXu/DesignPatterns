#pragma once
#include <iostream>
#include "Request.h"

class Handler
{
public:
	Handler(Handler* pNextHandler) : 
		m_pNextHandler(pNextHandler) {}

	void Handle(Request* pRequest)
	{
		if (canHandleRequest(pRequest))
			HandleRequest(pRequest);
		else{
			if (nullptr != m_pNextHandler)
				m_pNextHandler->Handle(pRequest);
		}	
	}
protected:
	virtual bool canHandleRequest(Request* pRequest) = 0;
	virtual void HandleRequest(Request* pRequest) = 0;

private:
	Handler* m_pNextHandler;
};

class Boss : public Handler
{
public:
	Boss(Handler* pNextHandler) : Handler(pNextHandler) {}
protected:
	virtual bool canHandleRequest(Request* pRequest)
	{
		return true;
	}
	virtual void HandleRequest(Request* pRequest)
	{
		std::cout << "Boss handled the request : " << pRequest->GetDescription() << std::endl;
	}
};

class Manager : public Handler
{
public:
	Manager(Handler* pNextHandler) : Handler(pNextHandler) {}
protected:
	virtual bool canHandleRequest(Request* pRequest)
	{
		return RequestLevel::Request_Level3 == pRequest->GetRequestLevel()
			|| RequestLevel::Request_Level2 == pRequest->GetRequestLevel();
			
	}
	virtual void HandleRequest(Request* pRequest)
	{
		std::cout << "Manager handled the request : " << pRequest->GetDescription() << std::endl;
	}
};

class Headman : public Handler
{
public:
	Headman(Handler* pNextHandler) : Handler(pNextHandler) {}
protected:
	virtual bool canHandleRequest(Request* pRequest)
	{
		return RequestLevel::Request_Level3 == pRequest->GetRequestLevel();
	}
	virtual void HandleRequest(Request* pRequest)
	{
		std::cout << "Headman handled the request : " << pRequest->GetDescription() << std::endl;
	}
};