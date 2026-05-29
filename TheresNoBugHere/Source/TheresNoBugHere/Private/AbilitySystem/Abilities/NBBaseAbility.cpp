// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/Abilities/NBBaseAbility.h"

#include "Kismet/KismetSystemLibrary.h"

static TAutoConsoleVariable<int32> CVarShouldDebugAbility(
	TEXT("NBGame.AbilitySystem.DebugAbility"),
	1,
	TEXT("1 to Enable Debug Ability")
);

// -----------------------------------------------------------------------
// ActivateAbility
// -----------------------------------------------------------------------
void UNBBaseAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (CVarShouldDebugAbility.GetValueOnAnyThread() > 0)
	{
		UKismetSystemLibrary::PrintString(this, FString::Format(TEXT("ActivateAbility:{0}"), {*GetNameSafe(this)}));
	}

	// 缓存激活信息，供后续 EndAbility 调用
	CachedHandle = Handle;
	CachedActorInfo = ActorInfo;
	CachedActivationInfo = ActivationInfo;

	// 重置时间轴
	ElapsedTime = 0.0f;
	PendingStartTasks.Reset();
	ActiveTasks.Reset();

	// 若没有任何 Task，直接结束技能
	if (BehaviorTasks.IsEmpty())
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	// 重置所有 Task 状态，并按 StartTime 升序收集到待启动列表
	for (UNBBehaviorTask* Task : BehaviorTasks)
	{
		if (Task)
		{
			Task->Reset();
			PendingStartTasks.Add(Task);
		}
	}
	PendingStartTasks.Sort([](const UNBBehaviorTask& A, const UNBBehaviorTask& B)
	{
		return A.StartTime < B.StartTime;
	});

	// 注册引擎全局 Tick 回调驱动时间轴
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(
		FTickerDelegate::CreateUObject(this, &UNBBaseAbility::OnTick));
}

// -----------------------------------------------------------------------
// EndAbility
// -----------------------------------------------------------------------
void UNBBaseAbility::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	StopTimeline();
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

// -----------------------------------------------------------------------
// OnTick —— 每帧驱动时间轴，返回 true 继续，false 停止
// -----------------------------------------------------------------------
bool UNBBaseAbility::OnTick(float DeltaTime)
{
	ElapsedTime += DeltaTime;

	// 启动到达 StartTime 的任务
	while (!PendingStartTasks.IsEmpty() && ElapsedTime >= PendingStartTasks[0]->StartTime)
	{
		UNBBehaviorTask* Task = PendingStartTasks[0];
		PendingStartTasks.RemoveAt(0);
		Task->bStarted = true;
		Task->OnTaskStart();
		ActiveTasks.Add(Task);
	}

	// 结束到达 EndTime 的任务
	for (int32 i = ActiveTasks.Num() - 1; i >= 0; --i)
	{
		UNBBehaviorTask* Task = ActiveTasks[i];
		if (ElapsedTime >= Task->EndTime || Task->bFinished)
		{
			Task->bFinished = true;
			Task->OnTaskEnd();
			ActiveTasks.RemoveAt(i);
		}
	}

	// 所有任务均已结束 → 结束技能
	if (PendingStartTasks.IsEmpty() && ActiveTasks.IsEmpty())
	{
		// 先移除 Ticker，再调用 EndAbility
		FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
		TickDelegateHandle.Reset();

		EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, false);
		return false;
	}

	return true;
}

// -----------------------------------------------------------------------
// StopTimeline —— 停止 Tick 并清理
// -----------------------------------------------------------------------
void UNBBaseAbility::StopTimeline()
{
	if (TickDelegateHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
		TickDelegateHandle.Reset();
	}
	PendingStartTasks.Reset();
	ActiveTasks.Reset();
}
