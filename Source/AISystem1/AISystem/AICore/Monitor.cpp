#include "Monitor.h"

Behavior* Monitor::Create(EPolicy _success, EPolicy _failure)
{
	return new Monitor(_success, _failure);
}

void Monitor::AddCondition(Behavior* childCondition)
{
	childs.Insert(childCondition, 0);
}

void Monitor::AddAction(Behavior* _child)
{
	childs.Add(_child);
}

FString Monitor::Name()
{
	return "Monitor";
}