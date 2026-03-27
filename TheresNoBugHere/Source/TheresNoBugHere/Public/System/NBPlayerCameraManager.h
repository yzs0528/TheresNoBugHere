// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "NBPlayerCameraManager.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FNBCameraRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PivotLocation;
};

UCLASS()
class THERESNOBUGHERE_API ANBPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;

protected:
	void UpdateCameraLocation(FTViewTarget& OutVT, float DeltaTime);
	void UpdateCameraRotation(FTViewTarget& OutVT, float DeltaTime);

public:
	void OnProcess(APawn* InPawn);

protected:
	UPROPERTY()
	TObjectPtr<APawn> ControlledPawn;

	UPROPERTY()
	FNBCameraRuntimeData LastRuntimeData;
};