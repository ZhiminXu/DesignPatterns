#pragma once
#include "Subject.h"


class SubjectImpl : public Subject
{
public:
	virtual void Operation();

private:
	std::map<std::string, std::string> m_mapKeyValue1;
	std::map<std::string, std::string> m_mapKeyValue2;
	std::map<std::string, std::string> m_mapKeyValue3;
	std::map<std::string, std::string> m_mapKeyValue4;
	std::map<std::string, std::string> m_mapKeyValue5;
	std::map<std::string, std::string> m_mapKeyValue6;
};

