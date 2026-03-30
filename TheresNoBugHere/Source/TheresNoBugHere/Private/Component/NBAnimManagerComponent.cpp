// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/NBAnimManagerComponent.h"

#include "Data/NBAnimationData.h"
#include "FunctionLibrary/NBAssetManagerFunctionLibrary.h"
#include "System/SubSystem/NBDebugMsgManagerSubSystem.h"


// Sets default values for this component's properties
UNBAnimManagerComponent::UNBAnimManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

UAnimMontage* UNBAnimManagerComponent::GetMontageByTag(const FGameplayTag& InTag)
{
	FNBRuntimeAnimSetData* AnimSetData = AnimSetVersion.Find(InTag);
	if (!AnimSetData)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			FString::Format(TEXT("UNBAnimManagerComponent::GetMontageByTag, Can't Find Aseet By Tag:{0}!"), {InTag.ToString()}), 
			ENBMsgType::Error);

		return nullptr;
	}

	return AnimSetData->GetAnimAsset<UAnimMontage>();
}

void UNBAnimManagerComponent::InitAnimSetByTable(UDataTable* AnimSetTable)
{
	if (!AnimSetTable)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			"UNBAnimManagerComponent::InitAnimSetByTable, AnimSetTable is null", 
			ENBMsgType::Error);
		return;
	}

	for (const auto& Row : AnimSetTable->GetRowMap())
	{
		const FNBAnimSetData* AnimSetData = reinterpret_cast<FNBAnimSetData*>(Row.Value);
		if (!AnimSetData->AnimTag.IsValid())
		{
			UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			FString::Format(TEXT("UNBAnimManagerComponent::InitAnimSetByTable, AnimSetData::AnimTag, Row:{0} is null"), {Row.Key.ToString()}), 
			ENBMsgType::Warning);
			continue;
		}

		UAnimationAsset* AnimAsset = UNBAssetManagerFunctionLibrary::SynLoadAsset<UAnimationAsset>(this, AnimSetData->AnimAsset);
		if (!AnimAsset && AnimSetData->AnimAsset.IsNull())
		{
			UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			FString::Format(TEXT("UNBAnimManagerComponent::InitAnimSetByTable, AnimSetData::AnimAsset, Row:{0} is null"), {Row.Key.ToString()}), 
			ENBMsgType::Warning);
			continue;
		}
		
		FNBRuntimeAnimSetData& RuntimeAnimSetData = AnimSetVersion.FindOrAdd(AnimSetData->AnimTag);
		RuntimeAnimSetData.UpdateAnimSet(AnimAsset);
	}
}

bool UNBAnimManagerComponent::ShouldUpdateAnim(const FGameplayTag& InTag, const int32 InVersion)
{
	if (FNBRuntimeAnimSetData* AnimSetData = AnimSetVersion.Find(InTag))
	{
		return InVersion != AnimSetData->GetVersion();
	}
	
	return false;
}

FNBRuntimeAnimSetData UNBAnimManagerComponent::GetAnimSetDataByTag(const FGameplayTag& InTag)
{
	if (FNBRuntimeAnimSetData* AnimSetData = AnimSetVersion.Find(InTag))
	{
		return *AnimSetData;
	}
	
	return FNBRuntimeAnimSetData();
}

