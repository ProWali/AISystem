#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <unordered_map>

class BlackBoardKeyType {};

class BlackBoardData_Bool: public BlackBoardKeyType
{
public:
	void SetValue(bool _value)
	{
		Value = _value;
	}
	bool GetValue()
	{
		return Value;
	}
private:
	bool Value;
};
class BlackBoardData_Int : public BlackBoardKeyType
{
public:
	void SetValue(int _value)
	{
		Value = _value;
	}
	int GetValue()
	{
		return Value;
	}
private:
	int Value;
};
class BlackBoardData_Float : public BlackBoardKeyType
{
public:
	void SetValue(float _value)
	{
		Value = _value;
	}
	float GetValue()
	{
		return Value;
	}
private:
	float Value;
};
class BlackBoardData_FVector : public BlackBoardKeyType
{
public:
public:
	void SetValue(FVector _value)
	{
		Value = _value;
	}
	FVector GetValue()
	{
		return Value;
	}
private:
	FVector Value;
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
	static bool GetValueAsBool(const FString& key)
	{
		return GetValue<BlackBoardData_Bool>(key)->GetValue();;
	}
	static int GetValueAsInt(const FString& key)
	{
		return GetValue<BlackBoardData_Int>(key)->GetValue();;
	}
	static float GetValueAsFloat(const FString& key)
	{
		return GetValue<BlackBoardData_Float>(key)->GetValue();;
	}
	static FVector GetValueAsFVector(const FString& key)
	{
		return GetValue<BlackBoardData_FVector>(key)->GetValue();;
	}

	static void SetValueAsBool(const FString& key, bool value)
	{
		SetValue<BlackBoardData_Bool>(key, new BlackBoardData_Bool())->SetValue(value);
	}
	static void SetValueAsBool(const FString& key, int value)
	{
		SetValue<BlackBoardData_Int>(key, new BlackBoardData_Int())->SetValue(value);
	}
	static void SetValueAsBool(const FString& key, float value)
	{
		SetValue<BlackBoardData_Float>(key, new BlackBoardData_Float())->SetValue(value);
	}
	static void SetValueAsBool(const FString& key, FVector value)
	{
		SetValue<BlackBoardData_FVector>(key, new BlackBoardData_FVector())->SetValue(value);
	}

protected:
	template<typename TDataClass>
	static TDataClass* SetValue(const FString& key, TDataClass* value)
	{
		black_data_map[key] = value;
		return value;
	}
	template<typename TDataClass>
	static TDataClass* GetValue(const FString& key)
	{
		return (TDataClass*)(black_data_map[key]);
	}

private:
	static std::unordered_map<FString, BlackBoardKeyType*> black_data_map;
};