#pragma once

#include "Behavior.h"

/*
װ������
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