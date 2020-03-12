#pragma once

#include "Composite.h"

/*
ѡ����������ִ��ÿ���ӽڵ�ֱ������һ��ִ�гɹ����߷���Running״̬
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