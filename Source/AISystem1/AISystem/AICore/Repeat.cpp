#include "Repeat.h"

Behavior* Repeat::Create(int _times)
{
	return new Repeat(_times);
}

void Repeat::Release()
{
	child->Release();
	delete this;
}

FString Repeat::Name()
{
	return TEXT("Repeat");
}

void Repeat::Init()
{

}

EStatus Repeat::Update(float DeltaTime)
{
	for (int i = 0; i < times; i++) {
		child->Tick(DeltaTime);
		if (child->IsRunning()) {
			return EStatus::Running;
		}
		else if (child->IsFailure()) {
			return EStatus::Failure;
		}
		child->Reset();
	}
	return EStatus::Success;
}