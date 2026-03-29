
#include "Animation/AnimNode/NBAnimNode_SequencePlayer.h"

#include "Component/NBAnimManagerComponent.h"
#include "System/SubSystem/NBDebugMsgManagerSubSystem.h"

void FNBAnimNode_SequencePlayer::PreUpdate(const UAnimInstance* InAnimInstance)
{
	FAnimNode_SequencePlayer::PreUpdate(InAnimInstance);

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
		Sequence = NewAnimSetData.GetAnimAsset<UAnimSequenceBase>();
		AnimVersion = NewAnimSetData.GetVersion();
	}
}
