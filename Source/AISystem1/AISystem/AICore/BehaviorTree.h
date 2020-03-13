#pragma once

/*
行为树节点
*/

#include "Behavior.h"

class BehaviorTree
{
public:
	BehaviorTree(Behavior* _root) { root = _root; }

	void SetRoot(Behavior* _root) { root = _root; }

	void Tick(float DeltaTime)
	{
		root->Tick(DeltaTime);
	}

	void Release()
	{
		root->Release();
	}
	
	bool haveRoot() 
	{
		return root != nullptr;
	}

	void PirntTree(Behavior* node);
	void PrintTree();
	int testIndex = 0;

private:
	Behavior* root = nullptr;
};