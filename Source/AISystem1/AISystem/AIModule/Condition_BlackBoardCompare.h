#pragma once

#include "../AICore/Condition.h"
#include "../AICore/BlackBoardData.h"

enum EKeyCompare
{
	Equal,					//=
	Not_Equal,				//!=
	Less_Than,				//<
	Less_Than_Or_Equal,		//<=
	Greater_Than,			//>
	Greater_Than_Or_Equal,	//>=
};

//黑板值比较： int 类型
class Condition_BlackBoardCompare_Int: public Condition
{
public:
	static Behavior* Create(const FString& key_board, EKeyCompare compare_type, int target_value);

	virtual FString Name() override;

protected:
	Condition_BlackBoardCompare_Int(const FString& key_board, EKeyCompare compare_type, int32 target_value) : Condition(false)
	{
		KeyBoard = key_board;
		CompareType = compare_type;
		TargetValue = target_value;
	}

	virtual EStatus Update(float DeltaTime) override;

private:
	FString KeyBoard;

	EKeyCompare CompareType;

	int TargetValue;
};

//黑板值比较： float 类型
class Condition_BlackBoardCompare_Float : public Condition
{
public:
	static Behavior* Create(const FString& key_board, EKeyCompare compare_type, float target_value);

	virtual FString Name() override;

protected:
	Condition_BlackBoardCompare_Float(const FString& key_board, EKeyCompare compare_type, float target_value) : Condition(false)
	{
		KeyBoard = key_board;
		CompareType = compare_type;
		TargetValue = target_value;
	}

	virtual EStatus Update(float DeltaTime) override;

private:
	FString KeyBoard;

	EKeyCompare CompareType;

	int32 TargetValue;
};