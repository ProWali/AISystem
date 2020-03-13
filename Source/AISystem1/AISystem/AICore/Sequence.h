#pragma once

#include "Composite.h"

/*
顺序器：依次执行所有节点，直到其中一个失败或者全部成功为止
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