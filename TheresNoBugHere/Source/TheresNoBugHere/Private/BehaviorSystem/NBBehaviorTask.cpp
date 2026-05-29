// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorSystem/NBBehaviorTask.h"

UNBBehaviorTask::UNBBehaviorTask()
{
}

void UNBBehaviorTask::Reset()
{
	bStarted = false;
	bFinished = false;
}

void UNBBehaviorTask::OnTaskStart_Implementation()
{
	// 子类或蓝图中实现具体逻辑
}

void UNBBehaviorTask::OnTaskEnd_Implementation()
{
	// 子类或蓝图中实现具体逻辑
}
