#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <unordered_map>

class BlackBoardKeyType
{
protected:
	template<typename T>
	static T GetValueFromMemory(const uint8* MemoryBlock)
	{
		return *((T*)MemoryBlock);
	}

	template<typename T>
	static void SetValueInMemory(uint8* MemoryBlock, const T& Value)
	{
		*((T*)MemoryBlock) = Value;
	}
};

template <typename T>
class BlackBoardTypeData
{
public:
	void SetValue(T _value)
	{
		value = _value;
	}
	T GetValue()
	{
		return value;
	}

private:
	T value;
};

class BlackBoardData_Bool: public BlackBoardKeyType
{
public:
	static void SetValue(BlackBoardData_Bool* KeyOb, uint8* RawData, bool Value)
	{
		SetValueInMemory<bool>(RawData, Value);
	}
	static bool GetValue(const BlackBoardData_Bool* KeyOb, const uint8* RawData)
	{
		return GetValueFromMemory<bool>(RawData);
	}
};
class BlackBoardData_Int : public BlackBoardKeyType
{
public:
	static void SetValue(BlackBoardData_Int* KeyOb, uint8* RawData, int Value)
	{
		SetValueInMemory<int>(RawData, Value);
	}
	static int GetValue(const BlackBoardData_Int* KeyOb, const uint8* RawData)
	{
		return GetValueFromMemory<int>(RawData);
	}
};
class BlackBoardData_Float : public BlackBoardKeyType
{
public:
	static void SetValue(BlackBoardData_Float* KeyOb, uint8* RawData, float Value)
	{
		SetValueInMemory<float>(RawData, Value);
	}
	static int GetValue(const BlackBoardData_Float* KeyOb, const uint8* RawData)
	{
		return GetValueFromMemory<float>(RawData);
	}
};
class BlackBoardData_FVector : public BlackBoardKeyType
{
public:
	static void SetValue(BlackBoardData_FVector* KeyOb, uint8* RawData, FVector Value)
	{
		SetValueInMemory<FVector>(RawData, Value);
	}
	static FVector GetValue(const BlackBoardData_FVector* KeyOb, const uint8* RawData)
	{
		return GetValueFromMemory<FVector>(RawData);
	}
};
class BlackBoardData_FString : public BlackBoardKeyType
{
public:
	void SetValue(FString* _value)
	{
		value = _value;
	}
	FString* GetValue()
	{
		return value;
	}

private:
	FString* value;
};
class BlackBoardData_Actor : public BlackBoardKeyType
{
public:
	void SetValue(AActor* _value)
	{
		value = _value;
	}
	AActor* GetValue()
	{
		return value;
	}

private:
	AActor* value;
};


class BlackBoardData
{
public:
	bool GetValueAsBool(const FString& key)
	{

	}
	int GetValueAsInt(const FString& key)
	{

	}
	float GetValueAsFloat(const FString& key)
	{

	}
	FVector GetValueAsFVector(const FString& key)
	{

	}
	FString GetValueAsFString(const FString& key)
	{

	}
	AActor* GetValueAsActor(const FString& key)
	{

	}

private:

	//std::unordered_map<int, >

};