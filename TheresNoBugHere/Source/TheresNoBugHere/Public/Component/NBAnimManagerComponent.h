// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/NBAnimationData.h"
#include "NBAnimManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THERESNOBUGHERE_API UNBAnimManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UNBAnimManagerComponent();

public:
	UFUNCTION(BlueprintCallable, Meta = (Categories = "NB_Tags.Animation.Montage"))
	UAnimMontage* GetMontageByTag(const FGameplayTag& InTag);
	
public:
	void InitAnimSetByTable(UDataTable* AnimSetTable);
	bool ShouldUpdateAnim(const FGameplayTag& InTag, const int32 InVersion);
	FNBRuntimeAnimSetData GetAnimSetDataByTag(const FGameplayTag& InTag);
	
	
protected:
	TMap<FGameplayTag, FNBRuntimeAnimSetData> AnimSetVersion; 
};
