#include "Sequence.h"

FString Sequence::Name()
{
	return TEXT("Sequence");
};

Behavior* Sequence::Create()
{
	return new Sequence();
};

void Sequence::Init()
{
	cur_child_index = 0;
};

EStatus Sequence::Update(float DeltaTime)
{
	while (true && cur_child_index < childs.Num())
	{
		EStatus s = childs[cur_child_index]->Tick(DeltaTime);
		if (s != EStatus::Success) {
			return s;
		}
		if (++cur_child_index >= childs.Num()) {
			return EStatus::Success;
		}
	}
	return EStatus::Invalid;
}