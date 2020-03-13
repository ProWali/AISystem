#include "BehaviorTreeBuilder.h"
#include "Action_Walk.h"
#include "../AICore/Sequence.h"
#include "../AICore/Action.h"
#include "../AICore/Condition.h"
#include "../AICore/Selector.h"
#include "../AICore/Parallel.h"

BehaviorTreeBuilder* BehaviorTreeBuilder::Sequence()
{
	Behavior* Sq = Sequence::Create();
	AddBehavior(Sq);
	return this;
}

BehaviorTreeBuilder* BehaviorTreeBuilder::Action(EActionType type)
{
	//根据输入参数创建不同动作节点
	Behavior* Ac;
	switch (type)
	{
	case EActionType::Walk:
		Ac = Action_Walk::Create();
		break;
	default:
		Ac = nullptr;
		break;
	}

	AddBehavior(Ac);

	return this;
}

BehaviorTreeBuilder* BehaviorTreeBuilder::Condition(EConditionType type)
{
	Behavior* Cd = nullptr;
	switch (type)
	{
	case EConditionType::IsSeeEnemy:
		break;

	default:
		Cd = nullptr;
		break;
	}

	AddBehavior(Cd);

	return this;
}

BehaviorTreeBuilder* BehaviorTreeBuilder::Selector()
{
	Behavior* St = Selector::Create();

	AddBehavior(St);

	return this;
}

BehaviorTreeBuilder* BehaviorTreeBuilder::Parallel(EPolicy success, EPolicy failure)
{
	Behavior* Pl = Parallel::Create(success, failure);

	AddBehavior(Pl);

	return this;
}

BehaviorTreeBuilder* BehaviorTreeBuilder::Back()
{
	NodeStack.pop();
	return this;
}

BehaviorTree* BehaviorTreeBuilder::End()
{
	while (!NodeStack.empty())
	{
		NodeStack.pop();
	}
	BehaviorTree* Tmp = new BehaviorTree(tree_root);
	tree_root = nullptr;
	return Tmp;
}

void BehaviorTreeBuilder::AddBehavior(Behavior* behavior)
{
	if (!tree_root)
	{
		tree_root = behavior;
	}
	else
	{
		NodeStack.top()->AddChild(behavior);
	}

	NodeStack.push(behavior);
}