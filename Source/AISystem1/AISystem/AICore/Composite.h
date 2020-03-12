#pragma once

#include "Behavior.h"

/*
��Ͻڵ����
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