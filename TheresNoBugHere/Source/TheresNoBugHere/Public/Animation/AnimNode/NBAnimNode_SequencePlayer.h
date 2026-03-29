#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimNode_SequencePlayer.h"
#include "NBAnimNode_SequencePlayer.generated.h"

class UNBAnimManagerComponent;

USTRUCT(BlueprintInternalUseOnly)
struct THERESNOBUGHERE_API FNBAnimNode_SequencePlayer : public FAnimNode_SequencePlayer
{
	GENERATED_BODY()

public:
	virtual bool HasPreUpdate() const override { return bShouldUpdate; }
	virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	
public:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FGameplayTag AnimTag;
	
protected:
	bool bShouldUpdate = true;
	int32 AnimVersion = 0;
	TWeakObjectPtr<UNBAnimManagerComponent> AnimManagerComponent;
};
