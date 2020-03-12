#pragma once

#include "Behavior.h"

/*
组合节点基类
*/

class Composite: public Behavior
{

public:
	virtual void AddChild(Behavior* _child) override;
	void RemoveChild(Behavior* _child);
	void ClearChild();
	virtual void Release();

protected:
	Composite() {}
	virtual ~Composite() {}

public:
	TArray<Behavior*> childs;
};