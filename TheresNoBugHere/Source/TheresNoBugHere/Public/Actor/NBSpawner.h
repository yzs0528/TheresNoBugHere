// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Info.h"
#include "NBSpawner.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API ANBSpawner : public AInfo
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	void OnSpawnDelay();
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnDelay = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBehaviorTree> BehaviorAsset;

protected:
	FTimerHandle SpawnDelayHandle;

	UPROPERTY()
	TObjectPtr<AAIController> AIController;
};
