#include "Action_Walk.h"

Behavior* Action_Walk::Create()
{
	return new Action_Walk();
}

FString Action_Walk::Name()
{
	return TEXT("Action_Walk");
}

EStatus Action_Walk::Update(float DeltaTime)
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

void Action_Walk::Init()
{
	test_walk_timer = 0;
	walk_flag = false;
}
