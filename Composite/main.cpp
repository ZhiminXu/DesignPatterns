#include "Component.h"

void main()
{
	Component* pRoot = new CompositeComponent("Root");

	Component* pType1 = new CompositeComponent("Type1");
	Component* pLeaf11 = new LeafComponent("Leaf1-1");
	Component* pLeaf12 = new LeafComponent("Leaf1-2");
	pType1->Add(pLeaf11);
	pType1->Add(pLeaf12);

	Component* pType2 = new CompositeComponent("Type2");
	Component* pLeaf21 = new LeafComponent("Leaf2-1");
	Component* pLeaf22 = new LeafComponent("Leaf2-2");
	pType2->Add(pLeaf21);
	pType2->Add(pLeaf22);

	pRoot->Add(pType1);
	pRoot->Add(pType2);
	pRoot->Process();

	delete pRoot;  pRoot = nullptr;
	delete pType1;  pType1 = nullptr;
	delete pLeaf11;  pLeaf11 = nullptr;
	delete pLeaf12;  pLeaf12 = nullptr;
	delete pType2;  pType2 = nullptr;
	delete pLeaf21;  pLeaf21 = nullptr;
	delete pLeaf22;  pLeaf22 = nullptr;


	std::cin.get();
}