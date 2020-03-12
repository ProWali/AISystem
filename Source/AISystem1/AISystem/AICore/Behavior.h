#pragma once

#include "CoreMinimal.h"

/*
��Ϊ���ڵ����
*/

//����״̬
enum EStatus
{
	Invalid,   //��ʼ״̬
	Success,   //�ɹ�
	Failure,   //ʧ��
	Running,   //����
	Aborted,   //��ֹ
};

//����ʧ������
enum class EPolicy
{
	RequireOne,	//ʧ��һ��
	RequireAll,	//ȫ��ʧ��
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