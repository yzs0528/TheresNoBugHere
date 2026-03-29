// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Data/NBAnimationData.h"
#include "NBAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UNBAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FNBAnimData_LocalMotion LocalMotionData;
};
