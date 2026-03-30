// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimGraphNode/NBAnimGraphNode_BlendSpacePlayer.h"

#include "AnimGraphCommands.h"
#include "Animation/BlendSpace1D.h"
#include "DetailLayoutBuilder.h"
#define LOCTEXT_NAMESPACE "TheresNoBugHereLoc"

FLinearColor UNBAnimGraphNode_BlendSpacePlayer::GetNodeTitleColor() const
{
	return FColor(200, 100, 0);
}

FText UNBAnimGraphNode_BlendSpacePlayer::GetTooltipText() const
{
	return LOCTEXT("TheresNoBugHereLoc_NBBlendSpacePlayer", "NBBlendSpacePlayer");
}

FText UNBAnimGraphNode_BlendSpacePlayer::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::Format(LOCTEXT("TheresNoBugHereLoc", "NBBlendSpacePlayer ({0})"), FText::FromString(Node.AnimTag.ToString()));
}

FString UNBAnimGraphNode_BlendSpacePlayer::GetNodeCategory() const
{
	return TEXT("AnimSet");
}

void UNBAnimGraphNode_BlendSpacePlayer::GetNodeContextMenuActions(UToolMenu* Menu,
	UGraphNodeContextMenuContext* Context) const
{
	if (!Context->bIsDebugging)
	{
		FToolMenuSection& Section = Menu->AddSection("AnimGraphNodeBlendSpacePlayer", NSLOCTEXT("A3Nodes", "BlendSpaceHeading", "Blend Space"));
		Section.AddMenuEntry(FAnimGraphCommands::Get().OpenRelatedAsset);
		Section.AddMenuEntry(FAnimGraphCommands::Get().ConvertToSeqEvaluator);
	}
}

void UNBAnimGraphNode_BlendSpacePlayer::BakeDataDuringCompilation(FCompilerResultsLog& MessageLog)
{
	Node.SetGroupName(SyncGroup_DEPRECATED.GroupName);
	Node.SetGroupRole(SyncGroup_DEPRECATED.GroupRole);
}

void UNBAnimGraphNode_BlendSpacePlayer::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	// 基类 UAnimGraphNode_BlendSpaceBase::CustomizeDetails 没有 ANIMGRAPH_API 导出，无法跨 DLL 调用 Super
	// 直接内联基类逻辑
	const UBlendSpace* BlendSpace = GetBlendSpace();
	if (BlendSpace)
	{
		TSharedRef<IPropertyHandle> XHandle = DetailBuilder.GetProperty(TEXT("Node.X"), GetClass());
		XHandle->SetPropertyDisplayName(FText::FromString(BlendSpace->GetBlendParameter(0).DisplayName));
		TSharedRef<IPropertyHandle> YHandle = DetailBuilder.GetProperty(TEXT("Node.Y"), GetClass());
		if (BlendSpace->IsA<UBlendSpace1D>())
		{
			DetailBuilder.HideProperty(YHandle);
		}
		else
		{
			YHandle->SetPropertyDisplayName(FText::FromString(BlendSpace->GetBlendParameter(1).DisplayName));
		}
	}
}

#undef LOCTEXT_NAMESPACE
