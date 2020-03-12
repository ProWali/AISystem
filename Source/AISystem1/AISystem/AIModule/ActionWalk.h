#pragma once

#include "../AICore/Action.h"

class ActionWalk: public Action
{
public:
	static Behavior* Create();

	virtual FString Name() override;

protected:
	ActionWalk() {};
	virtual ~ActionWalk() {};

	virtual void Init() override;

	virtual EStatus Update(float DeltaTime) override;

private:
	float test_walk_timer = 0;
	bool walk_flag = false;
};