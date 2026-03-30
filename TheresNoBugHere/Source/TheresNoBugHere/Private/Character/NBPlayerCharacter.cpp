// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "FunctionLibrary/NBGamePlayFunctionLibrary.h"
#include "System/NBPlayerController.h"
#include "System/NBPlayerState.h"


// Sets default values
ANBPlayerCharacter::ANBPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

FVector2D ANBPlayerCharacter::GetLastMovementInput()
{
	if (const ANBPlayerController* NBPlayerController = Cast<ANBPlayerController>(GetController()))
	{
		return NBPlayerController->LastMovementInput;
	}

	return FVector2D::ZeroVector;
}

FVector ANBPlayerCharacter::GetLastMovementWorldDirection()
{
	if (const ANBPlayerController* NBPlayerController = Cast<ANBPlayerController>(GetController()))
	{
		return NBPlayerController->LastMovementWorldDirection;
	}

	return FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ANBPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANBPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANBPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (HasAuthority())
	{
		if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
		{
			AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
		}

		GiveDefaultAbilities();
	}
}

void ANBPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent())
	{
		AbilitySystemComponent->InitAbilityActorInfo(GetPlayerState(), this);
	}
}

UAbilitySystemComponent* ANBPlayerCharacter::GetAbilitySystemComponent() const
{
	if (const ANBPlayerState* NBPlayerState = Cast<ANBPlayerState>(GetPlayerState()))
	{
		return NBPlayerState->GetAbilitySystemComponent();
	}

	return nullptr;
}

