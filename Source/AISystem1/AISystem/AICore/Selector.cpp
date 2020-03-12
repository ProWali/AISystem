#include "Selector.h"

FString Selector::Name()
{
	return TEXT("Selector");
};

Behavior* Selector::Create()
{
	return new Selector();
};

void Selector::Init()
{
	cur_child_index = 0;
};

EStatus Selector::Update(float DeltaTime)
{
	while (true && cur_child_index < childs.Num())
	{
		EStatus s = childs[cur_child_index]->Tick(DeltaTime);
		if (s != EStatus::Failure) {
			return s;
		}
		if (++cur_child_index >= childs.Num()) {
			return EStatus::Failure;
		}
	}
	return EStatus::Invalid;
}