#pragma once

#include "Behavior.h"

/*
�����ڵ����
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