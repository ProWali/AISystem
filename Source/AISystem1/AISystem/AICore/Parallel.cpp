#include "Parallel.h"

FString Parallel::Name()
{
	return TEXT("Parallel");
};

Behavior* Parallel::Create(EPolicy _success, EPolicy _failure)
{
	return new Parallel(_success, _failure);
};

EStatus Parallel::Update(float DeltaTime)
{
	int len = childs.Num();
	int success_num = 0, failure_num = 0, i = 0;
	for (i = 0; i < len; i++) {
		if (!childs[i]->IsTerminate()) {
			childs[i]->Tick(DeltaTime);
		}
		if (childs[i]->IsSuccess()) {
			success_num++;
			if (successPolicy == EPolicy::RequireOne) {
				childs[i]->Reset();
				return EStatus::Success;
			}
		}

		if (childs[i]->IsFailure()) {
			failure_num++;
			if (failurePolicy == EPolicy::RequireOne) {
				childs[i]->Reset();
				return EStatus::Failure;
			}
		}
	}
	if (failurePolicy == EPolicy::RequireAll && failure_num == len)
	{
		for (i = 0; i < len; i++) {
			childs[i]->Reset();
		}
		return EStatus::Failure;
	}

	if (successPolicy == EPolicy::RequireAll && success_num == len)
	{
		for (i = 0; i < len; i++) {
			childs[i]->Reset();
		}
		return EStatus::Success;
	}

	return EStatus::Running;
}

void Parallel::Terminate(EStatus _status)
{
	for (int i = 0, len = childs.Num(); i < len; i++) {
		if (childs[i]->IsRunning()) {
			childs[i]->Abort();
		}
	}
}