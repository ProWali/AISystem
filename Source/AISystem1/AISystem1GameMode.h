// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AISystem1GameMode.generated.h"

class BehaviorTreeBuilder;
class BehaviorTree;

UCLASS(minimalapi)
class AAISystem1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAISystem1GameMode();

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

private:
		BehaviorTreeBuilder* builder;

		BehaviorTree* bt;
};



