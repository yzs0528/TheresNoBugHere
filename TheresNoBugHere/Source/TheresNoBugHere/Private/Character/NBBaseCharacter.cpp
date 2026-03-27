// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"


// Sets default values
ANBBaseCharacter::ANBBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}


UAbilitySystemComponent* ANBBaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ANBBaseCharacter::GiveDefaultAbilities()
{
	UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent();
	if (!AbilitySystemComponent)
	{
		return;
	}
	
	for (const auto& Ability : DefaultAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

