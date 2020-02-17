#pragma once
#include <string>
#include <iostream>

class Tool
{
public:
	Tool(std::string strName) : m_strName(strName){}
	virtual ~Tool() {}
	virtual void Use() = 0;

private:
	std::string m_strName;
};

class Hammer : public Tool
{
public:
	Hammer() : Tool("Hammer") {}
	virtual void Use()
	{
		std::cout << " Hammering!" << std::endl;
	}
};


class Saw : public Tool
{
public:
	Saw() : Tool("Saw") {}
	virtual void Use()
	{
		std::cout << " Sawing" << std::endl;
	}
};

class ToolFactory
{
public:
	Tool* CreateTool(std::string strName)
	{
		if ("Hammer" == strName)
		{
			return new Hammer();
		}
		else if ("Saw" == strName)
		{
			return new Saw();
		}
		else
		{
			return nullptr;
		}
	}
};