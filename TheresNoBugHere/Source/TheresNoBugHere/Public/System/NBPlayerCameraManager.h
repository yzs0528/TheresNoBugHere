// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "NBPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API ANBPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;

public:
	void OnProcess(APawn* InPawn);

protected:
	UPROPERTY()
	TObjectPtr<APawn> ControlledPawn;
};