#include "Template.h"

void main()
{
	TemplateCookedRice* pTemplate = new Porridge(50);
	pTemplate->Cooking();
	delete pTemplate; pTemplate = nullptr;
}