#pragma once

#include "Behavior.h"

/*
动作节点基类
*/

class Action: public Behavior
{

public:
	virtual void Release() { delete this; }

protected:
	Action(){}
	virtual ~Action(){}
};