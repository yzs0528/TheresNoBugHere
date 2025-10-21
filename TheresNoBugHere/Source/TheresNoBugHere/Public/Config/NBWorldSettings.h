// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "NBWorldSettings.generated.h"

/**
 * 
 */

UCLASS(BlueprintType, config = Game, defaultconfig)
class THERESNOBUGHERE_API UNBSceneSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "MapSettings")
	float MapCellLength = 30.f;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "MapSettings")
	TArray<TEnumAsByte<EObjectTypeQuery>> BlockTraceObjectTypes;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "MapSettings")
	FString MapNavigationDataDir;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "AI")
	TSubclassOf<ACharacter> AIClass;
};