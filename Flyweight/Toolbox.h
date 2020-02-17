#pragma once
#include <map>

#include "Tool.h"

class ToolBox
{
public:
    ToolBox(ToolFactory* pFac) : m_pFac(pFac) {}

    virtual ~ToolBox()
    {
        for (auto iter = m_mapTools.begin(); iter != m_mapTools.end(); iter++)
        {
            delete (*iter).second;
            (*iter).second = nullptr;
        }
    }
    
	Tool* GetTool(std::string strName)
	{
        auto iter = m_mapTools.find(strName);
        if (iter != m_mapTools.end())
        {
            return  m_mapTools[strName];
        }
        else
        {
            Tool* pTool = m_pFac->CreateTool(strName);
            if (nullptr != pTool)
                m_mapTools[strName] = pTool;
            return pTool;
        }
	}

private:
	std::map<std::string, Tool*> m_mapTools;
    ToolFactory* m_pFac;
};

