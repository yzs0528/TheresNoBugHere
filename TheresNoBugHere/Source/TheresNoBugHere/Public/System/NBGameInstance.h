// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Config/NBCameraSettings.h"
#include "Engine/GameInstance.h"
#include "NBGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UNBGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	virtual void Init() override;

	void OpenLevelByTag(FGameplayTag InMapTag);
	void GetCurrentMapData(FNBMapData& OutMapData);

public:
	FGameplayTag CurrentMapTag;
};
