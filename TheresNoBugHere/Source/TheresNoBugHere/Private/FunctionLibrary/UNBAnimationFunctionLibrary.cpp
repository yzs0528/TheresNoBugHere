// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/UNBAnimationFunctionLibrary.h"

#include "Character/NBBaseCharacter.h"
#include "Component/NBAnimManagerComponent.h"

UNBAnimManagerComponent* UUNBAnimationFunctionLibrary::GetAnimManagerComponent(AActor* InOwner)
{
	ensure(InOwner);
	ANBBaseCharacter* Character = Cast<ANBBaseCharacter>(InOwner);
	if (!Character)
	{
		return nullptr;
	}

	return Character->GetAnimManagerComponent();
}

UAnimMontage* UUNBAnimationFunctionLibrary::GetMontageByTag(AActor* InOwner, FGameplayTag InTag)
{
	if (UNBAnimManagerComponent* AnimManagerComponent = GetAnimManagerComponent(InOwner))
	{
		return AnimManagerComponent->GetMontageByTag(InTag);
	}

	return nullptr;
}
