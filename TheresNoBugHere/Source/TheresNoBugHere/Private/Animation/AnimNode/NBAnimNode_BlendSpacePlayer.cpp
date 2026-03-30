// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNode/NBAnimNode_BlendSpacePlayer.h"

#include <System/SubSystem/NBDebugMsgManagerSubSystem.h>

#include "Component/NBAnimManagerComponent.h"

void FNBAnimNode_BlendSpacePlayer::PreUpdate(const UAnimInstance* InAnimInstance)
{
	FAnimNode_BlendSpacePlayer::PreUpdate(InAnimInstance);

	if (!AnimTag.IsValid())
	{
		bShouldUpdate = false;
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(InAnimInstance, 
			TEXT("FNBAnimNode_SequencePlayer::PreUpdate, AnimTag is null"),
			ENBMsgType::Error);
		return;
	}
	
	if (!AnimManagerComponent.IsValid())
	{
		AnimManagerComponent = InAnimInstance->GetOwningActor()->FindComponentByClass<UNBAnimManagerComponent>();
	}

	if (!AnimManagerComponent.IsValid())
	{
		bShouldUpdate = false;
		return;
	}
	
	if (AnimManagerComponent->ShouldUpdateAnim(AnimTag, AnimVersion))
	{
		FNBRuntimeAnimSetData NewAnimSetData = AnimManagerComponent->GetAnimSetDataByTag(AnimTag);
		SetBlendSpace(NewAnimSetData.GetAnimAsset<UBlendSpace>());
		AnimVersion = NewAnimSetData.GetVersion();
	}
}
