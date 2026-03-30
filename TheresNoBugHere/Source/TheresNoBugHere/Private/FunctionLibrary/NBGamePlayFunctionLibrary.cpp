// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/NBGamePlayFunctionLibrary.h"

#include <Component/NBCharacterStateComponent.h>
#include <System/SubSystem/NBDebugMsgManagerSubSystem.h>

#include "GameplayTagContainer.h"
#include "Character/NBBaseCharacter.h"
#include "System/NBPlayerController.h"

FVector UNBGamePlayFunctionLibrary::InputDirectionToWorldDirection(const FVector2D& InputDirection,
                                                                   const FRotator& BaseRotation)
{
	if (InputDirection.IsZero())
	{
		return FVector::ZeroVector;
	}
	
	const FRotator YawRotation(0, BaseRotation.Yaw, 0);

	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	return ((ForwardDirection * InputDirection.Y) + (RightDirection * InputDirection.X));
}

bool UNBGamePlayFunctionLibrary::ActorHasMovementInput(AActor* OwningActor)
{
	ensure(OwningActor);
	const ANBBaseCharacter* Character = Cast<ANBBaseCharacter>(OwningActor);
	if (!Character)
	{
		return false;
	}

	return ControllerHasMovementInput(Character->GetController());
}

bool UNBGamePlayFunctionLibrary::ControllerHasMovementInput(AController* OwningController)
{
	ensure(OwningController);
	const ANBPlayerController* Controller = Cast<ANBPlayerController>(OwningController);
	if (!Controller)
	{
		return false;
	}
	
	return Controller->bHasMovementInput;
}

FVector2D UNBGamePlayFunctionLibrary::GetLastMovementInput(AActor* OwningActor)
{
	ensure(OwningActor);
	ANBBaseCharacter* Character = Cast<ANBBaseCharacter>(OwningActor);
	if (!Character)
	{
		return FVector2D::ZeroVector;
	}

	return Character->GetLastMovementInput();
}

FVector UNBGamePlayFunctionLibrary::GetLastMovementWorldDirection(AActor* OwningActor)
{
	ensure(OwningActor);
	ANBBaseCharacter* Character = Cast<ANBBaseCharacter>(OwningActor);
	if (!Character)
	{
		return FVector::ZeroVector;
	}

	return Character->GetLastMovementWorldDirection();
}

UNBCharacterStateComponent* UNBGamePlayFunctionLibrary::GetCharacterStateComponent(AActor* OwningActor)
{
	if (!ensure(OwningActor))
	{
		return nullptr;
	}
	
	const ANBBaseCharacter* Character = Cast<ANBBaseCharacter>(OwningActor);
	if (!Character)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(OwningActor,
			TEXT("UNBGamePlayFunctionLibrary::AddStateTag, OwningActor Is Not A ANBBaseCharacter!"),
			ENBMsgType::Error);
	}

	return Character->GetCharacterStateComponent();
}

void UNBGamePlayFunctionLibrary::AddStateTag(AActor* OwningActor, FGameplayTag InTag)
{
	UNBCharacterStateComponent* StateComp = GetCharacterStateComponent(OwningActor);
	if (!StateComp)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(OwningActor, 
			FString::Format(TEXT("UNBGamePlayFunctionLibrary::AddStateTag, Can't Find State Component, Character:{0}!"), {GetNameSafe(OwningActor)}), 
			ENBMsgType::Error);
	}

	StateComp->AddStateTag(InTag);
}

void UNBGamePlayFunctionLibrary::RemoveStateTag(AActor* OwningActor, FGameplayTag InTag)
{
	UNBCharacterStateComponent* StateComp = GetCharacterStateComponent(OwningActor);
	if (!StateComp)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(OwningActor, 
			FString::Format(TEXT("UNBGamePlayFunctionLibrary::AddStateTag, Can't Find State Component, Character:{0}!"), {GetNameSafe(OwningActor)}), 
			ENBMsgType::Error);
	}

	StateComp->RemoveStateTag(InTag);
}
