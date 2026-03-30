// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimNodes/AnimNode_BlendSpacePlayer.h"
#include "NBAnimNode_BlendSpacePlayer.generated.h"

/**
 * 
 */

class UNBAnimManagerComponent;

USTRUCT(BlueprintInternalUseOnly)
struct THERESNOBUGHERE_API FNBAnimNode_BlendSpacePlayer : public FAnimNode_BlendSpacePlayer
{
	GENERATED_BODY()

public:
	virtual bool HasPreUpdate() const override { return bShouldUpdate; }
	virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	
public:
	UPROPERTY(EditAnywhere, Category = "AnimSet", Meta = (Categories = "NB_Tags.Animation.BlendSpace"))
	FGameplayTag AnimTag;
	
protected:
	bool bShouldUpdate = true;
	int32 AnimVersion = 0;
	TWeakObjectPtr<UNBAnimManagerComponent> AnimManagerComponent;
};
