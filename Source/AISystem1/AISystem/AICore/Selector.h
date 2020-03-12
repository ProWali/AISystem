#pragma once

#include "Composite.h"

/*
选择器：依次执行每个子节点直到其中一个执行成功或者返回Running状态
*/

class Selector : public Composite
{
public:
	virtual FString Name() override;
	static Behavior* Create();

protected:
	Selector() {};
	virtual ~Selector() {}
	virtual void Init() override;
	virtual EStatus Update(float DeltaTime) override;

protected:
	int32 cur_child_index;
};