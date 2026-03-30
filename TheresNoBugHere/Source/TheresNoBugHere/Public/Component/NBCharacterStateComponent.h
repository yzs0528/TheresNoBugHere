// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "NBCharacterStateComponent.generated.h"

/**
 * 角色状态变更委托
 * @param StateTag  发生变更的状态Tag
 * @param bAdded    true = 状态被激活, false = 状态被移除
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCharacterStateChanged, FGameplayTag, StateTag, bool, bAdded);

/**
 * 基于 FGameplayTag + 引用计数 的角色状态管理组件
 *
 * 设计要点：
 *  - 每个 Tag 维护一个引用计数，AddStateTag/RemoveStateTag 成对调用
 *  - 计数 > 0 时 Tag 处于激活状态，计数归零时 Tag 被移除
 *  - 避免多个系统同时操作同一 Tag 时互相覆盖
 *  - 提供 HasStateTag / HasAnyStateTag / HasAllStateTags 查询接口
 *  - 提供 OnStateChanged 委托供外部监听状态变化
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THERESNOBUGHERE_API UNBCharacterStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UNBCharacterStateComponent();

	// -----------------------------------------------------------------------
	// 状态写入接口
	// -----------------------------------------------------------------------

	/**
	 * 添加一个状态 Tag（引用计数 +1）
	 * 当计数从 0 变为 1 时触发 OnStateChanged(Tag, true)
	 */
	UFUNCTION(BlueprintCallable, Category = "CharacterState")
	void AddStateTag(const FGameplayTag& StateTag);

	/**
	 * 移除一个状态 Tag（引用计数 -1）
	 * 当计数归零时触发 OnStateChanged(Tag, false)
	 * 计数已为 0 时调用此函数会打印警告，不会使计数变为负数
	 */
	UFUNCTION(BlueprintCallable, Category = "CharacterState")
	void RemoveStateTag(const FGameplayTag& StateTag);

	/**
	 * 强制清除某个 Tag 的所有引用计数
	 * 若 Tag 处于激活状态则触发 OnStateChanged(Tag, false)
	 */
	UFUNCTION(BlueprintCallable, Category = "CharacterState")
	void ForceRemoveStateTag(const FGameplayTag& StateTag);

	/** 强制清除所有状态 Tag */
	UFUNCTION(BlueprintCallable, Category = "CharacterState")
	void ClearAllStateTags();

	// -----------------------------------------------------------------------
	// 状态查询接口
	// -----------------------------------------------------------------------

	/** 是否拥有指定 Tag（计数 > 0） */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	bool HasStateTag(const FGameplayTag& StateTag) const;

	/** 是否拥有容器中任意一个 Tag */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	bool HasAnyStateTag(const FGameplayTagContainer& Tags) const;

	/** 是否同时拥有容器中所有 Tag */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	bool HasAllStateTags(const FGameplayTagContainer& Tags) const;

	/** 获取当前所有激活状态 Tag 的快照 */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	FGameplayTagContainer GetActiveStateTags() const;

	/** 获取指定 Tag 的当前引用计数（调试用） */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	int32 GetStateTagCount(const FGameplayTag& StateTag) const;

	// -----------------------------------------------------------------------
	// 委托
	// -----------------------------------------------------------------------

	/** 状态 Tag 发生变化时广播（激活或移除） */
	UPROPERTY(BlueprintAssignable, Category = "CharacterState")
	FOnCharacterStateChanged OnStateChanged;

private:
	/**
	 * Tag -> 引用计数 映射表
	 * 不暴露给蓝图，通过接口函数操作
	 */
	UPROPERTY(VisibleAnywhere, Category = "CharacterState|Debug")
	TMap<FGameplayTag, int32> StateTagCountMap;
};