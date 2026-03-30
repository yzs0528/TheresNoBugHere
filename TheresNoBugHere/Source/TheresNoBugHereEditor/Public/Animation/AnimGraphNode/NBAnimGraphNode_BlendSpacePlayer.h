// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_BlendSpaceBase.h"
#include "Animation/AnimNode/NBAnimNode_BlendSpacePlayer.h"
#include "NBAnimGraphNode_BlendSpacePlayer.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHEREEDITOR_API UNBAnimGraphNode_BlendSpacePlayer : public UAnimGraphNode_BlendSpaceBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FNBAnimNode_BlendSpacePlayer Node;

	// UEdGraphNode interface
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FString GetNodeCategory() const override;
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
	// End of UK2Node interface

	// UAnimGraphNode_Base interface
	virtual void BakeDataDuringCompilation(class FCompilerResultsLog& MessageLog) override;
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	// End of UAnimGraphNode_Base interface
};
