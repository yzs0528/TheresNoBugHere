// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NBBehaviorTask.generated.h"

/**
 * 行为任务基类
 * 每个任务配有启动时间点与结束时间点，在 BehaviorObject 的时间轴上被触发
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class THERESNOBUGHERE_API UNBBehaviorTask : public UObject
{
	GENERATED_BODY()

public:
	UNBBehaviorTask();

	/** 任务在行为时间轴上的启动时间（秒） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BehaviorTask")
	float StartTime = 0.0f;

	/** 任务在行为时间轴上的结束时间（秒） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BehaviorTask")
	float EndTime = 1.0f;

	/** 任务是否已启动 */
	UPROPERTY(BlueprintReadOnly, Category = "BehaviorTask")
	bool bStarted = false;

	/** 任务是否已结束 */
	UPROPERTY(BlueprintReadOnly, Category = "BehaviorTask")
	bool bFinished = false;

	/** 重置任务状态，供复用 */
	void Reset();

	
protected:

	/** 当任务启动时调用（可在蓝图中重写） */
	UFUNCTION(BlueprintNativeEvent, Category = "BehaviorTask")
	void OnTaskStart();
	virtual void OnTaskStart_Implementation();

	/** 当任务结束时调用（可在蓝图中重写） */
	UFUNCTION(BlueprintNativeEvent, Category = "BehaviorTask")
	void OnTaskEnd();
	virtual void OnTaskEnd_Implementation();
};