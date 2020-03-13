#include "BehaviorTree.h"
#include "Composite.h"

void BehaviorTree::PirntTree(Behavior* node)
{
	if (node != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("NameTree: %s, index: %d"), *(node->Name()), testIndex);
		Composite* tempCom = static_cast<Composite*>(node);
		if (tempCom != nullptr && tempCom->childs.Num() > 0) {
			for (int i = 0; i < tempCom->childs.Num(); i++) {
				PirntTree(tempCom->childs[i]);
			}
		}
	}
}

void BehaviorTree::PrintTree()
{
	testIndex = 0;
	PirntTree(root);
}