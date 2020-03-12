#include "ActionWalk.h"

Behavior* ActionWalk::Create()
{
	return new ActionWalk();
}

FString ActionWalk::Name()
{
	return TEXT("ActionWalk");
}

EStatus ActionWalk::Update(float DeltaTime)
{
	test_walk_timer += DeltaTime;
	if (test_walk_timer > 2) {
		UE_LOG(LogTemp, Warning, TEXT("Walk Arrived~"));
		return EStatus::Success;
	}
	if (!walk_flag) {
		walk_flag = true;
		UE_LOG(LogTemp, Warning, TEXT("Walk Begin~"));
	}
	return EStatus::Running;
}

void ActionWalk::Init()
{
	test_walk_timer = 0;
	walk_flag = false;
}
