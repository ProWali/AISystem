#pragma once

#include "Behavior.h"

/*
�����ڵ����
*/

class Action: public Behavior
{

public:
	virtual void Release() { delete this; }

protected:
	Action(){}
	virtual ~Action(){}
};