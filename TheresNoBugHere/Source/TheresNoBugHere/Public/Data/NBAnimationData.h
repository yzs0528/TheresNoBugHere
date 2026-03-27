// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NBAnimationData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FNBAnimSetData : FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName AnimTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<UAnimSequenceBase> AnimAsset;

	bool operator==(const FNBAnimSetData& Other) const
	{
		return AnimTag == Other.AnimTag && AnimAsset == Other.AnimAsset;
	}
};
