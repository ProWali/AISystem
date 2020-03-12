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

};

EStatus Sequence::Update(float DeltaTime)
{
	for (int i = 0, len = childs.Num(); i < len; i++) {
		EStatus s = childs[i]->Tick(DeltaTime);
		if (s != EStatus::Success) {
			return s;
		}
	}
	return EStatus::Success;
}