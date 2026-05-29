// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BehaviorSystem/NBBehaviorTask.h"
#include "Containers/Ticker.h"
#include "NBBaseAbility.generated.h"

/**
 * 技能基类
 * 支持在编辑器中配置 BehaviorTask 列表，ActivateAbility 时按时间轴依次触发所有 Task，
 * 全部 Task 结束后自动调用 EndAbility。
 */
UCLASS()
class THERESNOBUGHERE_API UNBBaseAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	/** 配置在此技能上的行为任务列表 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "BehaviorTask")
	TArray<TObjectPtr<UNBBehaviorTask>> BehaviorTasks;

private:
	/** 当前时间轴已流逝时间 */
	float ElapsedTime = 0.0f;

	/** 尚未启动的任务（按 StartTime 升序排列） */
	TArray<UNBBehaviorTask*> PendingStartTasks;

	/** 已启动但尚未结束的任务 */
	TArray<UNBBehaviorTask*> ActiveTasks;

	/** 缓存激活信息，供 EndAbility 使用 */
	FGameplayAbilitySpecHandle CachedHandle;
	const FGameplayAbilityActorInfo* CachedActorInfo = nullptr;
	FGameplayAbilityActivationInfo CachedActivationInfo;

	/** 每帧驱动时间轴的 Ticker 句柄 */
	FTSTicker::FDelegateHandle TickDelegateHandle;

	/** 注册到引擎 Tick 的回调，返回 true 继续 Tick，false 停止 */
	bool OnTick(float DeltaTime);

	/** 停止 Tick 并清理状态 */
	void StopTimeline();
};
