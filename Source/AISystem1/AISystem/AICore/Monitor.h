#pragma once

#include "Parallel.h"

/*
监视器: 持续检查假设条件的有效性，一旦条件不满足，即时退出当前行为
*/

class Monitor :public Parallel
{
public:
	static Behavior* Create(EPolicy _success, EPolicy _failure);
	void AddCondition(Behavior* Condition);
	void AddAction(Behavior* Action);
	virtual FString Name() override;

protected:
	Monitor(EPolicy _success, EPolicy _failure) :Parallel(_success, _failure) {}
	virtual ~Monitor() {}
};