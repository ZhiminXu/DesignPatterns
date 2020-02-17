#pragma once
#include <list>
#include <iostream>
class Component
{
public:
	Component(std::string strName) : m_strName(strName) {}
	virtual ~Component() {}
	virtual void Process() = 0;
	virtual void Add(Component* pComponent) = 0;
	virtual void Remove(Component* pComponent) = 0;

protected:
	std::string m_strName;
};

class CompositeComponent : public Component
{
public:
	CompositeComponent(std::string strName) : Component(strName) {}

	virtual void Process()
	{
		std::cout << "CompositeComponent " << m_strName << " processing¡­¡­" << std::endl;

		for(auto var : m_listComponent)
			var->Process();
	}
	virtual void Add(Component* pComponent)
	{
		m_listComponent.push_back(pComponent);
	}
	virtual void Remove(Component* pComponent)
	{
		m_listComponent.remove(pComponent);
	}
private:
	std::list<Component*> m_listComponent;
};


class LeafComponent : public Component
{
public:
	LeafComponent(std::string strName) : Component(strName) {}

	virtual void Process()
	{
		std::cout << "LeafComponent " << m_strName << " processing¡­¡­" << std::endl;
	}
	virtual void Add(Component* pComponent)
	{
	}
	virtual void Remove(Component* pComponent)
	{
	}
};

