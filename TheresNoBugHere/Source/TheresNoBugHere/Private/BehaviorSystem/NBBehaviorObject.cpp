// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorSystem/NBBehaviorObject.h"
#include "BehaviorSystem/NBBehaviorTask.h"

UNBBehaviorObject::UNBBehaviorObject()
{
}

void UNBBehaviorObject::Start()
{
	// 重置时间与所有任务状态
	ElapsedTime = 0.0f;
	bRunning = true;

	for (UNBBehaviorTask* Task : Tasks)
	{
		if (Task)
		{
			Task->Reset();
		}
	}

	// 若没有任何任务，立即完成
	if (Tasks.IsEmpty())
	{
		bRunning = false;
		OnBehaviorFinished();
		OnFinished.ExecuteIfBound();
	}
}

void UNBBehaviorObject::Tick(float DeltaTime)
{
	if (!bRunning)
	{
		return;
	}

	ElapsedTime += DeltaTime;

	UpdateTasks();

	if (AreAllTasksFinished())
	{
		bRunning = false;
		OnBehaviorFinished();
		OnFinished.ExecuteIfBound();
	}
}

void UNBBehaviorObject::UpdateTasks()
{
	for (UNBBehaviorTask* Task : Tasks)
	{
		if (!Task)
		{
			continue;
		}

		// 到达启动时间且尚未启动
		if (!Task->bStarted && ElapsedTime >= Task->StartTime)
		{
			Task->bStarted = true;
			Task->OnTaskStart();
		}

		// 已启动、到达结束时间且尚未结束
		if (Task->bStarted && !Task->bFinished && ElapsedTime >= Task->EndTime)
		{
			Task->bFinished = true;
			Task->OnTaskEnd();
		}
	}
}

bool UNBBehaviorObject::AreAllTasksFinished() const
{
	if (Tasks.IsEmpty())
	{
		return true;
	}

	for (const UNBBehaviorTask* Task : Tasks)
	{
		if (Task && !Task->bFinished)
		{
			return false;
		}
	}
	return true;
}

void UNBBehaviorObject::OnBehaviorFinished_Implementation()
{
	// 子类或蓝图中实现具体逻辑
}
