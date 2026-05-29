// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NBBehaviorObject.generated.h"

class UNBBehaviorTask;

DECLARE_DELEGATE(FOnBehaviorObjectFinished);

/**
 * 行为对象
 * 由多个 BehaviorTask 组成，按照时间轴依次触发各任务的启动与结束
 * 当所有任务都运行结束后，触发完成回调并等待销毁
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class THERESNOBUGHERE_API UNBBehaviorObject : public UObject
{
	GENERATED_BODY()

public:
	UNBBehaviorObject();

	/** 该行为包含的所有任务列表（按 StartTime 升序排列） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "BehaviorObject")
	TArray<TObjectPtr<UNBBehaviorTask>> Tasks;

	/** 当前行为已运行的时间（秒） */
	UPROPERTY(BlueprintReadOnly, Category = "BehaviorObject")
	float ElapsedTime = 0.0f;

	/** 行为是否正在运行 */
	UPROPERTY(BlueprintReadOnly, Category = "BehaviorObject")
	bool bRunning = false;

	/** 所有任务完成后的回调（由 BehaviorSystemComponent 绑定） */
	FOnBehaviorObjectFinished OnFinished;

	/** 启动行为，重置所有任务状态并开始计时 */
	void Start();

	/** 每帧推进时间轴，触发任务的启动与结束 */
	void Tick(float DeltaTime);

	/** 当行为对象所有任务完成时调用（可在蓝图中重写） */
	UFUNCTION(BlueprintNativeEvent, Category = "BehaviorObject")
	void OnBehaviorFinished();
	virtual void OnBehaviorFinished_Implementation();

private:
	/** 检查并触发各任务的启动/结束事件 */
	void UpdateTasks();

	/** 是否所有任务都已结束 */
	bool AreAllTasksFinished() const;
};
