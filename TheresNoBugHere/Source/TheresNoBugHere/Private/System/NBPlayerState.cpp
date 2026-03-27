// Fill out your copyright notice in the Description page of Project Settings.


#include "System/NBPlayerState.h"

#include "AbilitySystemComponent.h"

ANBPlayerState::ANBPlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}
