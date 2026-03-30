// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimGraphNode/NBAnimGraphNode_SequencePlayer.h"

#include "AnimGraphCommands.h"
#define LOCTEXT_NAMESPACE "TheresNoBugHereLoc"

FLinearColor UNBAnimGraphNode_SequencePlayer::GetNodeTitleColor() const
{
	return FColor(200, 100, 100);
}

FText UNBAnimGraphNode_SequencePlayer::GetTooltipText() const
{
	return LOCTEXT("TheresNoBugHereLoc_NBSequencePlayer", "NBSequencePlayer");
}

FText UNBAnimGraphNode_SequencePlayer::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::Format(LOCTEXT("TheresNoBugHereLoc", "NBSequencePlayer ({0})"), FText::FromString(Node.AnimTag.ToString()));
}

FString UNBAnimGraphNode_SequencePlayer::GetNodeCategory() const
{
	return TEXT("AnimSet");
}

void UNBAnimGraphNode_SequencePlayer::GetNodeContextMenuActions(UToolMenu* Menu,
	UGraphNodeContextMenuContext* Context) const
{
	if (!Context->bIsDebugging)
	{
		FToolMenuSection& Section = Menu->AddSection("AnimGraphNodeSequencePlayer", NSLOCTEXT("A3Nodes", "SequencePlayerHeading", "Sequence Player"));
		Section.AddMenuEntry(FAnimGraphCommands::Get().OpenRelatedAsset);
		Section.AddMenuEntry(FAnimGraphCommands::Get().ConvertToSeqEvaluator);
	}
}

void UNBAnimGraphNode_SequencePlayer::BakeDataDuringCompilation(FCompilerResultsLog& MessageLog)
{
	Node.SetGroupName(SyncGroup_DEPRECATED.GroupName);
	Node.SetGroupRole(SyncGroup_DEPRECATED.GroupRole);
}

#undef LOCTEXT_NAMESPACE