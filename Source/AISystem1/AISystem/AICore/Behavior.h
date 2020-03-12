#pragma once

#include "CoreMinimal.h"

/*
行为树节点基类
*/

//返回状态
enum EStatus
{
	Invalid,   //初始状态
	Success,   //成功
	Failure,   //失败
	Running,   //运行
	Aborted,   //终止
};

//返回失败类型
enum class EPolicy
{
	RequireOne,	//失败一个
	RequireAll,	//全部失败
};

class Behavior
{

public:
	EStatus Tick(float DeltaTime);

	virtual void Release() = 0;

	EStatus GetStatus();

	void Reset();
	void Abort();

	bool IsTerminate();
	bool IsRunning();
	bool IsSuccess();
	bool IsFailure();

	virtual FString Name() = 0;
	virtual void AddChild(Behavior* _child) {};

protected:
	Behavior() : status(EStatus::Invalid) {};

	virtual void Init() {};

	virtual EStatus Update(float DeltaTime) = 0;

	virtual void Terminate(EStatus _status) {};

protected:
	EStatus status;
};