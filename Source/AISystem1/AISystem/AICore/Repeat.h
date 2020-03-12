#pragma once

#include "Decorator.h"

/*
装饰器：重复执行子节点
*/

class Repeat : public Decorator
{
public:
	static Behavior* Create(int _times);
	virtual void Release();
	virtual FString Name();

protected:
	Repeat(int _times) :times(_times) {}
	virtual ~Repeat() {}
	virtual void Init();
	virtual EStatus Update(float DeltaTime) override;
protected:
	int times = 3;
};