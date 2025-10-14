// Fill out your copyright notice in the Description page of Project Settings.


#include "System/NBPlayerCameraManager.h"

#include "Config/NBCameraSettings.h"

void ANBPlayerCameraManager::BeginPlay()
{
	Super::BeginPlay();
}

void ANBPlayerCameraManager::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	Super::UpdateViewTargetInternal(OutVT, DeltaTime);

	if (!ControlledPawn)
	{
		ControlledPawn = GetOwningPlayerController()->AcknowledgedPawn;
	}

	if (!ControlledPawn)
	{
		return;
	}

	const UNBCameraSettings* CameraSettings = GetDefault<UNBCameraSettings>();
	if (!CameraSettings)
	{
		return;
	}

	const FVector& PawnLocation = ControlledPawn->GetActorLocation();
	OutVT.POV.Location = PawnLocation + FVector(CameraSettings->CameraLength, 0.f, 0.f);
	OutVT.POV.Rotation = FRotator::ZeroRotator;
}

void ANBPlayerCameraManager::OnProcess(APawn* InPawn)
{
	ControlledPawn = InPawn;
}
