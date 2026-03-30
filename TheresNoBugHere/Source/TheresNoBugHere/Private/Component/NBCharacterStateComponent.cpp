// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/NBCharacterStateComponent.h"

UNBCharacterStateComponent::UNBCharacterStateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// -----------------------------------------------------------------------
// 状态写入
// -----------------------------------------------------------------------

void UNBCharacterStateComponent::AddStateTag(const FGameplayTag& StateTag)
{
	if (!StateTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("[NBCharacterState] AddStateTag: 无效的 Tag，操作被忽略"));
		return;
	}

	int32& Count = StateTagCountMap.FindOrAdd(StateTag, 0);
	const bool bWasInactive = (Count == 0);
	Count++;

	if (bWasInactive)
	{
		// 计数从 0 变为 1，状态首次激活
		OnStateChanged.Broadcast(StateTag, true);
		UE_LOG(LogTemp, Verbose, TEXT("[NBCharacterState] 状态激活: %s (Count=%d)"), *StateTag.ToString(), Count);
	}
	else
	{
		UE_LOG(LogTemp, Verbose, TEXT("[NBCharacterState] 状态计数增加: %s (Count=%d)"), *StateTag.ToString(), Count);
	}
}

void UNBCharacterStateComponent::RemoveStateTag(const FGameplayTag& StateTag)
{
	if (!StateTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("[NBCharacterState] RemoveStateTag: 无效的 Tag，操作被忽略"));
		return;
	}

	int32* CountPtr = StateTagCountMap.Find(StateTag);
	if (!CountPtr || *CountPtr <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[NBCharacterState] RemoveStateTag: Tag [%s] 的引用计数已为 0，请检查 Add/Remove 是否成对调用"), *StateTag.ToString());
		return;
	}

	(*CountPtr)--;

	if (*CountPtr == 0)
	{
		// 计数归零，状态移除
		StateTagCountMap.Remove(StateTag);
		OnStateChanged.Broadcast(StateTag, false);
		UE_LOG(LogTemp, Verbose, TEXT("[NBCharacterState] 状态移除: %s"), *StateTag.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Verbose, TEXT("[NBCharacterState] 状态计数减少: %s (Count=%d)"), *StateTag.ToString(), *CountPtr);
	}
}

void UNBCharacterStateComponent::ForceRemoveStateTag(const FGameplayTag& StateTag)
{
	if (!StateTag.IsValid())
	{
		return;
	}

	const bool bWasActive = StateTagCountMap.Contains(StateTag);
	StateTagCountMap.Remove(StateTag);

	if (bWasActive)
	{
		OnStateChanged.Broadcast(StateTag, false);
		UE_LOG(LogTemp, Verbose, TEXT("[NBCharacterState] 强制移除状态: %s"), *StateTag.ToString());
	}
}

void UNBCharacterStateComponent::ClearAllStateTags()
{
	// 对每个激活的 Tag 广播移除事件
	for (const auto& Pair : StateTagCountMap)
	{
		OnStateChanged.Broadcast(Pair.Key, false);
	}
	StateTagCountMap.Empty();
	UE_LOG(LogTemp, Verbose, TEXT("[NBCharacterState] 所有状态已清除"));
}

// -----------------------------------------------------------------------
// 状态查询
// -----------------------------------------------------------------------

bool UNBCharacterStateComponent::HasStateTag(const FGameplayTag& StateTag) const
{
	const int32* CountPtr = StateTagCountMap.Find(StateTag);
	return CountPtr && *CountPtr > 0;
}

bool UNBCharacterStateComponent::HasAnyStateTag(const FGameplayTagContainer& Tags) const
{
	for (const FGameplayTag& Tag : Tags)
	{
		if (HasStateTag(Tag))
		{
			return true;
		}
	}
	return false;
}

bool UNBCharacterStateComponent::HasAllStateTags(const FGameplayTagContainer& Tags) const
{
	for (const FGameplayTag& Tag : Tags)
	{
		if (!HasStateTag(Tag))
		{
			return false;
		}
	}
	return true;
}

FGameplayTagContainer UNBCharacterStateComponent::GetActiveStateTags() const
{
	FGameplayTagContainer Result;
	for (const auto& Pair : StateTagCountMap)
	{
		if (Pair.Value > 0)
		{
			Result.AddTag(Pair.Key);
		}
	}
	return Result;
}

int32 UNBCharacterStateComponent::GetStateTagCount(const FGameplayTag& StateTag) const
{
	const int32* CountPtr = StateTagCountMap.Find(StateTag);
	return CountPtr ? *CountPtr : 0;
}