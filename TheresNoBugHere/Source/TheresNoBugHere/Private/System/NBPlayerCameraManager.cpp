// Fill out your copyright notice in the Description page of Project Settings.


#include "System/NBPlayerCameraManager.h"

#include "Config/NBCameraSettings.h"
#include "Kismet/KismetMathLibrary.h"
#include "System/NBSceneWorldSubsystem.h"

void ANBPlayerCameraManager::BeginPlay()
{
	Super::BeginPlay();
}

void ANBPlayerCameraManager::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	Super::UpdateViewTargetInternal(OutVT, DeltaTime);

	if (!GetOwningPlayerController())
	{
		return;
	}
	
	if (!ControlledPawn)
	{
		ControlledPawn = GetOwningPlayerController()->AcknowledgedPawn;
	}

	if (!ControlledPawn)
	{
		return;
	}
	
	UpdateCameraLocation(OutVT, DeltaTime);
	UpdateCameraRotation(OutVT, DeltaTime);

	GetOwningPlayerController()->SetControlRotation(OutVT.POV.Rotation);
}

void ANBPlayerCameraManager::UpdateCameraLocation(FTViewTarget& OutVT, float DeltaTime)
{
	const UNBCameraSettings* CameraSettings = GetDefault<UNBCameraSettings>();
	if (!CameraSettings)
	{
		return;
	}

	const FVector& PawnLocation = ControlledPawn->GetActorLocation();
	LastRuntimeData.PivotLocation = FMath::VInterpTo(LastRuntimeData.PivotLocation, PawnLocation, DeltaTime, CameraSettings->CameraFollowSpeed);
	const float HorizontalAngleRadians = FMath::DegreesToRadians(CameraSettings->CameraHorizontalAngle);
	const float VerticalAngleRadians = FMath::DegreesToRadians(CameraSettings->CameraVerticalAngle);
	const FVector& CameraDirection = FVector(FMath::Cos(VerticalAngleRadians), FMath::Sin(HorizontalAngleRadians), -FMath::Sin(VerticalAngleRadians));
	OutVT.POV.Location = LastRuntimeData.PivotLocation - CameraDirection * CameraSettings->CameraLength;
	//OutVT.POV.Location = FMath::VInterpTo(GetCameraCacheView().Location, TargetCameraLocation, DeltaTime, CameraSettings->CameraFollowSpeed);

	// if (const UNBSceneWorldSubsystem* SceneSubSystem = GetWorld()->GetSubsystem<UNBSceneWorldSubsystem>())
	// {
	// 	OutVT.POV.Location = SceneSubSystem->TryCameraLimit(OutVT.POV.Location);
	// }
}

void ANBPlayerCameraManager::UpdateCameraRotation(FTViewTarget& OutVT, float DeltaTime)
{
	const UNBCameraSettings* CameraSettings = GetDefault<UNBCameraSettings>();
	if (!CameraSettings)
	{
		return;
	}
	
	FVector LookDirection = (LastRuntimeData.PivotLocation - OutVT.POV.Location).GetSafeNormal();
	FRotator TargetRotator = UKismetMathLibrary::MakeRotFromXY(LookDirection, FVector::RightVector);
	if (CameraSettings->bEffectCameraRotateLayOnRoll || CameraSettings->bEffectCameraRotateLayOnPitch || CameraSettings->bEffectCameraRotateLayOnYaw)
	{
		const FVector& PawnLocation = ControlledPawn->GetActorLocation();
		LookDirection = (PawnLocation - OutVT.POV.Location).GetSafeNormal();
		const FRotator LookPawnRotator = UKismetMathLibrary::MakeRotFromXY(LookDirection, FVector::RightVector);
		TargetRotator.Roll = CameraSettings->bEffectCameraRotateLayOnRoll ? LookPawnRotator.Roll : TargetRotator.Roll;
		TargetRotator.Pitch = CameraSettings->bEffectCameraRotateLayOnPitch ? LookPawnRotator.Pitch : TargetRotator.Pitch;
		TargetRotator.Yaw = CameraSettings->bEffectCameraRotateLayOnYaw ? LookPawnRotator.Yaw : TargetRotator.Yaw;
	}
	OutVT.POV.Rotation = FMath::RInterpTo(GetCameraCacheView().Rotation, TargetRotator, DeltaTime, CameraSettings->CameraRotateSpeed);
	OutVT.POV.Rotation.Roll = 0.f;
}

void ANBPlayerCameraManager::OnProcess(APawn* InPawn)
{
	if (!ensure(InPawn))
	{
		return;
	}
	
	ControlledPawn = InPawn;
	LastRuntimeData.PivotLocation = InPawn->GetActorLocation();
}
