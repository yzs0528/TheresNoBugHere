// Fill out your copyright notice in the Description page of Project Settings.


#include "System/SubSystem/NBAssetManagerSubSystem.h"

#include "System/SubSystem/NBDebugMsgManagerSubSystem.h"

void UNBAssetManagerSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
}

void UNBAssetManagerSubSystem::Deinitialize()
{
	Super::Deinitialize();
}

UObject* UNBAssetManagerSubSystem::SynLoadObject(const FSoftObjectPath& Path)
{
	UObject* Object = StreamableManager.LoadSynchronous(Path);
	if (!Object)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
		FString::Format(TEXT("UNBAssetManagerSubSystem::SynLoadObject, Load Failed:{0}"), {Path.ToString()}) , 
		ENBMsgType::Error);
	}
	return Object;
}
