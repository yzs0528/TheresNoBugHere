// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NBCharacterData.generated.h"

/**
 * 
 */
UENUM()
enum class ECharacterType : uint8
{
	None,
	Player,
	
	//Enemy
	Normal,
	Elites,
	Boss,
};


USTRUCT(BlueprintType)
struct FNBCharacterData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CharacterID = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AvatarID = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECharacterType CharacterType = ECharacterType::None;
};
