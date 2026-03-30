// Fill out your copyright notice in the Description page of Project Settings.

#include "System/NBPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FunctionLibrary/NBGamePlayFunctionLibrary.h"
#include "GamePlayTags/NBTags.h"
#include "Character/NBBaseCharacter.h"
#include "Component/NBCharacterStateComponent.h"
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

	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem  = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for	(const auto Context : MappingContexts)
		{
			EnhancedInputLocalPlayerSubsystem->AddMappingContext(Context, 0);
		}
	}
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(InputAction_Move, ETriggerEvent::Triggered, this, &ANBPlayerController::Move);
		EnhancedInputComponent->BindAction(InputAction_Move, ETriggerEvent::Completed, this, &ANBPlayerController::MoveEnd);
		EnhancedInputComponent->BindAction(InputAction_Look, ETriggerEvent::Triggered, this, &ANBPlayerController::Look);
		
		EnhancedInputComponent->BindAction(InputAction_DefaultAttack, ETriggerEvent::Started, this, &ANBPlayerController::Action_DefaultAttack);
		EnhancedInputComponent->BindAction(InputAction_Dash, ETriggerEvent::Started, this, &ANBPlayerController::Action_Dash);
		EnhancedInputComponent->BindAction(InputAction_Ability01, ETriggerEvent::Started, this, &ANBPlayerController::Action_Ability01);
		EnhancedInputComponent->BindAction(InputAction_Ability02, ETriggerEvent::Started, this, &ANBPlayerController::Action_Ability02);
	}
		
}

void ANBPlayerController::ActiveAbility(const FGameplayTag& AbilityTag) const
{
	if (UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()))
	{
		ASC->TryActivateAbilitiesByTag(AbilityTag.GetSingleTagContainer());
	}
}

bool ANBPlayerController::IsInputBlocked() const
{
	if (const ANBBaseCharacter* ControlledCharacter = Cast<ANBBaseCharacter>(GetPawn()))
	{
		if (UNBCharacterStateComponent* StateComp = ControlledCharacter->GetCharacterStateComponent())
		{
			return StateComp->HasStateTag(NB_Tags::State::BlockInput);
		}
	}
	return false;
}

bool ANBPlayerController::IsMoveBlocked() const
{
	if (const ANBBaseCharacter* ControlledCharacter = Cast<ANBBaseCharacter>(GetPawn()))
	{
		if (UNBCharacterStateComponent* StateComp = ControlledCharacter->GetCharacterStateComponent())
		{
			return StateComp->HasStateTag(NB_Tags::State::BlockInput)
				|| StateComp->HasStateTag(NB_Tags::State::BlockMove);
		}
	}
	return false;
}

bool ANBPlayerController::IsAbilityBlocked() const
{
	if (const ANBBaseCharacter* ControlledCharacter = Cast<ANBBaseCharacter>(GetPawn()))
	{
		if (UNBCharacterStateComponent* StateComp = ControlledCharacter->GetCharacterStateComponent())
		{
			return StateComp->HasStateTag(NB_Tags::State::BlockInput)
				|| StateComp->HasStateTag(NB_Tags::State::BlockAbility);
		}
	}
	return false;
}

void ANBPlayerController::Move(const FInputActionValue& Value)
{
	if (AcknowledgedPawn)
	{
		LastMovementInput = Value.Get<FVector2D>();
		if (IsMoveBlocked())
		{
			return;
		}

		bHasMovementInput = true;
		LastMovementWorldDirection = UNBGamePlayFunctionLibrary::InputDirectionToWorldDirection(LastMovementInput, GetControlRotation());
		AcknowledgedPawn->AddMovementInput(LastMovementWorldDirection, 1.f);
	}
}

void ANBPlayerController::MoveEnd(const FInputActionValue& Value)
{
	bHasMovementInput = false;
}

void ANBPlayerController::Look(const FInputActionValue& Value)
{
	
}

void ANBPlayerController::Action_DefaultAttack(const FInputActionValue& Value)
{
	if (!IsAbilityBlocked())
	{
		ActiveAbility(NB_Tags::Abilities::DefaultAttack);
	}
}

void ANBPlayerController::Action_Dash(const FInputActionValue& Value)
{
	if (!IsAbilityBlocked())
	{
		ActiveAbility(NB_Tags::Abilities::Dash);
	}
}

void ANBPlayerController::Action_Ability01(const FInputActionValue& Value)
{
	if (!IsAbilityBlocked())
	{
		ActiveAbility(NB_Tags::Abilities::Ability01);
	}
}

void ANBPlayerController::Action_Ability02(const FInputActionValue& Value)
{
	if (!IsAbilityBlocked())
	{
		ActiveAbility(NB_Tags::Abilities::Ability02);
	}
}
