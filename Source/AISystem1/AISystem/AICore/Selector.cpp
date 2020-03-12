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

};

EStatus Selector::Update(float DeltaTime)
{
	for (int i = 0, len = childs.Num(); i < len; i++) {
		EStatus s = childs[i]->Tick(DeltaTime);
		if (s != EStatus::Failure) {
			return s;
		}
	}
	return EStatus::Failure;
}