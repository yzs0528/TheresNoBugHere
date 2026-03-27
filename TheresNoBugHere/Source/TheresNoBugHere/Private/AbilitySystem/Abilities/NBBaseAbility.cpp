// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/NBBaseAbility.h"

#include "Kismet/KismetSystemLibrary.h"

static TAutoConsoleVariable<int32> CVarShouldDebugAbility(
	TEXT("NBGame.AbilitySystem.DebugAbility"),
	1,
	TEXT("1 to Enable Debug Ability")
	);

void UNBBaseAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (CVarShouldDebugAbility.GetValueOnAnyThread() > 0)
	{
		UKismetSystemLibrary::PrintString(this, FString::Format(TEXT("ActivateAbility:{0}"), {*GetNameSafe(this)}));
	}
}
