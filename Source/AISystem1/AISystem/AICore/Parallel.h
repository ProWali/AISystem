#pragma once

#include "Composite.h"

/*
�������������Ϊ�ڵ㲢��ִ��
*/

class Parallel : public Composite
{
public:
	virtual FString Name() override;
	static Behavior* Create(EPolicy _success, EPolicy _failure);

protected:
	Parallel(EPolicy _success, EPolicy _failure) :successPolicy(_success), failurePolicy(_failure) {};
	virtual ~Parallel() {}
	virtual EStatus Update(float DeltaTime) override;
	virtual void Terminate(EStatus _status) override;

protected:
	EPolicy successPolicy;
	EPolicy failurePolicy;
};