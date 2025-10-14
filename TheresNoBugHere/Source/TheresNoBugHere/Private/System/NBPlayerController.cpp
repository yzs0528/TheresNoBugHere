// Fill out your copyright notice in the Description page of Project Settings.

#include "System/NBPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "System/NBPlayerCameraManager.h"

void ANBPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ANBPlayerCameraManager* CameraManager = Cast<ANBPlayerCameraManager>(PlayerCameraManager);
	if (CameraManager)
	{
		CameraManager->OnProcess(InPawn);
	}
}

void ANBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem  = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (EnhancedInputLocalPlayerSubsystem && MappingContext)
	{
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(MappingContext, 0);
	}
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ANBPlayerController::MoveRight);
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &ANBPlayerController::MoveUp);
	}
		
}

void ANBPlayerController::MoveRight(const FInputActionValue& Value)
{
	if (AcknowledgedPawn)
	{
		float InputDirection = Value.Get<float>();
		
		AcknowledgedPawn->AddMovementInput(FVector(0.f, 1, 0.f), InputDirection);
	}
}

void ANBPlayerController::MoveUp(const FInputActionValue& Value)
{
	if (AcknowledgedPawn)
	{
		float InputDirection = Value.Get<float>();
		
		AcknowledgedPawn->AddMovementInput(FVector(0.f, 0.f, 1), InputDirection);
	}
}
