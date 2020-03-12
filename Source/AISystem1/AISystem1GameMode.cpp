// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AISystem1GameMode.h"
#include "AISystem1Character.h"
#include "UObject/ConstructorHelpers.h"
#include "AISystem/AIModule/BehaviorTreeBuilder.h"

AAISystem1GameMode::AAISystem1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PrimaryActorTick.bCanEverTick = true;
}

void AAISystem1GameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	bt->Tick(DeltaSeconds);
}

void AAISystem1GameMode::BeginPlay()
{
	Super::BeginPlay();
	builder = new BehaviorTreeBuilder();
	bt = builder
		->Selector()
		->Action(Walk)
		->Back()
		->Back()
		->End();

	bt->PrintTree();
	
}