#pragma once

#include "Behavior.h"

/*
动作节点基类
*/

class Condition : public Behavior
{

public:
	virtual void Release() { delete this; }

protected:
	Condition(bool _IsNegation): IsNegation(_IsNegation) {}
	virtual ~Condition() {}

protected:
	bool IsNegation = false;
};