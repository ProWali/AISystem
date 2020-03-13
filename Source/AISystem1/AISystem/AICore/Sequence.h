#pragma once

#include "Composite.h"

/*
˳����������ִ�����нڵ㣬ֱ������һ��ʧ�ܻ���ȫ���ɹ�Ϊֹ
*/

class Sequence : public Composite
{
public:
	virtual FString Name() override;
	static Behavior* Create();

protected:
	Sequence() {};
	virtual ~Sequence() {};
	virtual void Init();
	virtual EStatus Update(float DeltaTime) override;

};