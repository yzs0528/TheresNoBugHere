// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "NBCameraSettings.generated.h"

/**
 * 
 */


UCLASS(BlueprintType, config = Game, defaultconfig)
class THERESNOBUGHERE_API UNBCameraSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	float CameraHorizontalAngle = 45.f;
	
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	float CameraVerticalAngle = 45.f;
	
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	float CameraLength = 50000.f;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	float CameraFollowSpeed = 10.f;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	float CameraRotateSpeed = 10.f;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	bool bEffectCameraRotateLayOnRoll = false;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	bool bEffectCameraRotateLayOnPitch = false;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CameraSettings")
	bool bEffectCameraRotateLayOnYaw = false;
};
