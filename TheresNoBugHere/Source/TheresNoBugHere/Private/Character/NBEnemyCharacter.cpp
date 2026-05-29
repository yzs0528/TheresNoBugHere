// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBEnemyCharacter.h"

#include "AbilitySystemComponent.h"


ANBEnemyCharacter::ANBEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

UAbilitySystemComponent* ANBEnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ANBEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (!ASC)
	{
		return;
	}

	ASC->InitAbilityActorInfo(this, this);

	if (HasAuthority())
	{
		GiveDefaultAbilities();
	}
}


