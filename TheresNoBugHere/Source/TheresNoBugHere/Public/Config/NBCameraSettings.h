// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "NBCameraSettings.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNBMapData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D CameraLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MovementLimit;
};

UCLASS(BlueprintType, config = Game, defaultconfig)
class THERESNOBUGHERE_API UNBCameraSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	float CameraLength = 50000.f;
};


UCLASS(BlueprintType, config = Game, defaultconfig)
class THERESNOBUGHERE_API UNBSceneSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	TMap<FGameplayTag, FNBMapData> MapData;
};