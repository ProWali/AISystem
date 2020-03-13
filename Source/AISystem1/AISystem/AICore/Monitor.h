#pragma once

#include "Parallel.h"

/*
������: ������������������Ч�ԣ�һ�����������㣬��ʱ�˳���ǰ��Ϊ
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