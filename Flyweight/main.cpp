#include "Toolbox.h"
#include "Tool.h"

void main()
{
	ToolFactory* pFac = new ToolFactory();
	ToolBox* pBox = new ToolBox(pFac);

	Tool* pTool = pBox->GetTool("Hammer");
	pTool->Use();

}