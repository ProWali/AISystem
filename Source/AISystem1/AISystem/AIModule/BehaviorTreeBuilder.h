#pragma once
#include "../AICore/Behavior.h"
#include <stack>
#include "../AICore/BehaviorTree.h"

enum EActionType
{
	Walk,
	Fight,
};

enum EConditionType
{
	IsSeeEnemy,
	IsEnemyDead,
};

class BehaviorTreeBuilder
{
public:
	BehaviorTreeBuilder() {};
	~BehaviorTreeBuilder() {};
	BehaviorTreeBuilder* Sequence();
	BehaviorTreeBuilder* Action(EActionType type);
	BehaviorTreeBuilder* Condition(EConditionType type);
	BehaviorTreeBuilder* Selector();
	BehaviorTreeBuilder* Parallel(EPolicy success, EPolicy failure);
	BehaviorTreeBuilder* Back();
	BehaviorTree* End();

private:
	void AddBehavior(Behavior* behavior);

private:
	Behavior* tree_root = nullptr;
	std::stack<Behavior*> NodeStack;
};