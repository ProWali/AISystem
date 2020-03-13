#include "Behavior.h"

EStatus Behavior::Tick(float DeltaTime)
{
	if (status != EStatus::Running)
	{
		Init();
	}

	status = Update(DeltaTime);
	
	if (status != EStatus::Running)
	{
		Terminate(status);
	}
	return status;
}

EStatus Behavior::GetStatus() 
{
	return status;
};

void Behavior::Reset() 
{
	status = EStatus::Invalid; 
};

void Behavior::Abort() 
{
	Terminate(EStatus::Aborted); status = EStatus::Aborted;
};

bool Behavior::IsTerminate() 
{ 
	return status == EStatus::Success || status == EStatus::Failure;
};

bool Behavior::IsRunning() 
{ 
	return status == EStatus::Running;
};

bool Behavior::IsSuccess()
{ 
	return status == EStatus::Success;
};

bool Behavior::IsFailure() 
{
	return status == EStatus::Failure;
};