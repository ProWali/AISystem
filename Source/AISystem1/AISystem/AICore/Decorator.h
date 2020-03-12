#pragma once

#include "Behavior.h"

/*
动作节点基类
*/

class Decorator : public Behavior
{

public:
	virtual void AddChild(Behavior* _child) { child = _child; }

protected:
	Decorator() {}
	virtual ~Decorator() {}

protected:
	Behavior* child;

};