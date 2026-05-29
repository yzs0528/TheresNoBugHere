// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorSystem/NBBehaviorSystemComponent.h"
#include "BehaviorSystem/NBBehaviorObject.h"

UNBBehaviorSystemComponent::UNBBehaviorSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNBBehaviorSystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UNBBehaviorSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 逆序遍历，方便在循环中安全移除已完成的行为
	for (int32 i = RunningBehaviors.Num() - 1; i >= 0; --i)
	{
		UNBBehaviorObject* Behavior = RunningBehaviors[i];
		if (Behavior && Behavior->bRunning)
		{
			Behavior->Tick(DeltaTime);
		}
	}
}

void UNBBehaviorSystemComponent::StartBehavior(UNBBehaviorObject* BehaviorObject)
{
	if (!BehaviorObject)
	{
		return;
	}

	// 绑定完成回调
	BehaviorObject->OnFinished.BindUObject(this, &UNBBehaviorSystemComponent::OnBehaviorFinished, BehaviorObject);

	RunningBehaviors.Add(BehaviorObject);
	BehaviorObject->Start();
}

void UNBBehaviorSystemComponent::StopAllBehaviors()
{
	for (UNBBehaviorObject* Behavior : RunningBehaviors)
	{
		if (Behavior)
		{
			Behavior->bRunning = false;
		}
	}
	RunningBehaviors.Empty();
}

TArray<UNBBehaviorObject*> UNBBehaviorSystemComponent::GetRunningBehaviors() const
{
	TArray<UNBBehaviorObject*> Result;
	Result.Reserve(RunningBehaviors.Num());
	for (const TObjectPtr<UNBBehaviorObject>& Behavior : RunningBehaviors)
	{
		Result.Add(Behavior.Get());
	}
	return Result;
}

void UNBBehaviorSystemComponent::OnBehaviorFinished(UNBBehaviorObject* FinishedBehavior)
{
	RunningBehaviors.Remove(FinishedBehavior);
}