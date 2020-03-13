#include "Composite.h"

void Composite::AddChild(Behavior* _child)
{
	childs.Add(_child);
}

void Composite::RemoveChild(Behavior* _child)
{
	for (int i = 0, len = childs.Num(); i < len; i++)
	{
		if (childs[i] == _child) {
			childs.Remove(_child);
			break;
		}
	}
}

void Composite::ClearChild()
{
	childs.Empty();
}

void Composite::Release()
{
	for (auto it : childs)
	{
		it->Release();
	}
	delete this;
}