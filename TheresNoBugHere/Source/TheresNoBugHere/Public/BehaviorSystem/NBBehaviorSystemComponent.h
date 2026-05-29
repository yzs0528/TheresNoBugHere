// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NBBehaviorSystemComponent.generated.h"

class UNBBehaviorObject;

/**
 * 行为系统组件
 * 挂载到角色上，负责驱动 BehaviorObject 的时间轴推进
 * 通过 StartBehavior 启动一个 BehaviorObject
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THERESNOBUGHERE_API UNBBehaviorSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UNBBehaviorSystemComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * 启动一个 BehaviorObject
	 * @param BehaviorObject 要运行的行为对象实例
	 */
	UFUNCTION(BlueprintCallable, Category = "BehaviorSystem")
	void StartBehavior(UNBBehaviorObject* BehaviorObject);

	/**
	 * 停止当前正在运行的所有行为
	 */
	UFUNCTION(BlueprintCallable, Category = "BehaviorSystem")
	void StopAllBehaviors();

	/** 获取当前正在运行的行为对象列表（只读） */
	UFUNCTION(BlueprintCallable, Category = "BehaviorSystem")
	TArray<UNBBehaviorObject*> GetRunningBehaviors() const;

private:
	/** 当前正在运行的行为对象列表 */
	UPROPERTY()
	TArray<TObjectPtr<UNBBehaviorObject>> RunningBehaviors;

	/** 当某个 BehaviorObject 完成时的回调处理 */
	void OnBehaviorFinished(UNBBehaviorObject* FinishedBehavior);
};
