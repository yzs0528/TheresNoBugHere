// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UNBAnimationFunctionLibrary.generated.h"

struct FGameplayTag;
class UNBAnimManagerComponent;
/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UUNBAnimationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "AnimSet")
	static UNBAnimManagerComponent* GetAnimManagerComponent(AActor* InOwner);

	UFUNCTION(BlueprintPure, Category = "AnimSet", Meta = (Categories = "NB_Tags.Animation.Montage"))
	static UAnimMontage* GetMontageByTag(AActor* InOwner, FGameplayTag InTag);
};
