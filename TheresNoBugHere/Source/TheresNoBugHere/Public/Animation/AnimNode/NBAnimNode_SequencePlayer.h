#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNode_SequencePlayer.h"
#include "NBAnimNode_SequencePlayer.generated.h"

USTRUCT()
struct FNBAnimNode_SequencePlayer : public FAnimNode_SequencePlayer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FName AnimTag;
};
