#include "Condition_BlackBoardCompare.h"

template<typename TType>
bool CompareResult(TType type_a, TType type_b, EKeyCompare compare_type)
{
	switch (compare_type)
	{
	case EKeyCompare::Equal:
		return type_a == type_b;
	case EKeyCompare::Not_Equal:
		return type_a != type_b;
	case EKeyCompare::Less_Than:
		return type_a < type_b;
	case EKeyCompare::Less_Than_Or_Equal:
		return type_a <= type_b;
	case EKeyCompare::Greater_Than:
		return type_a > type_b;
	case EKeyCompare::Greater_Than_Or_Equal:
		return type_a >= type_b;
	}
	return false;
}

Behavior* Condition_BlackBoardCompare_Int::Create(const FString& key_board, EKeyCompare compare_type, int target_value)
{
	return new Condition_BlackBoardCompare_Int(key_board, compare_type, target_value);
}

FString Condition_BlackBoardCompare_Int::Name()
{
	return TEXT("Condition_BlackBoardCompare_Int");
}

EStatus Condition_BlackBoardCompare_Int::Update(float DeltaTime)
{
	int32 sour_value = BlackBoardData::GetValueAsInt(KeyBoard);
	if (CompareResult(sour_value, TargetValue, CompareType))
	{
		return EStatus::Success;
	}
	return EStatus::Failure;
}