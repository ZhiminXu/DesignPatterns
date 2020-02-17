#pragma once
#include <string>

enum class RequestLevel
{
	Request_Level1,
	Request_Level2,
	Request_Level3
};

class Request
{
public:
	Request(std::string strDescription, RequestLevel rl):
		m_strDescription(strDescription), m_RequestLevel(rl) {}

	std::string GetDescription()
	{
		return m_strDescription;
	}

	RequestLevel GetRequestLevel()
	{
		return m_RequestLevel;
	}
private:
	std::string m_strDescription;
	RequestLevel m_RequestLevel;
};

