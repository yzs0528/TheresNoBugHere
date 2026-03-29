// Fill out your copyright notice in the Description page of Project Settings.


#include "System/SubSystem/NBDebugMsgManagerSubSystem.h"

#include "Kismet/KismetSystemLibrary.h"

static TAutoConsoleVariable<int32> CVarShowDebug(
	TEXT("NBGame.DebugMsgManager.ShowDebug"),
	1,
	TEXT("1 to ShowDebug")
	);

static TAutoConsoleVariable<int32> CVarShowDebugOwner(
	TEXT("NBGame.DebugMsgManager.ShowDebugOwner"),
	1,
	TEXT("1 to ShowDebugOwner")
	);

static TAutoConsoleVariable<int32> CVarShowDebugOnScreen(
	TEXT("NBGame.DebugMsgManager.ShowDebugOnScreen"),
	1,
	TEXT("1 to ShowDebugOnScreen")
	);

FLinearColor UNBDebugMsgManagerSubSystem::GetColorFromType(const ENBMsgType MsgType)
{
	switch (MsgType)
	{
	case ENBMsgType::Log:
		return FLinearColor::Green;
	case ENBMsgType::Warning:
		return FLinearColor::Yellow;
	default:
		return FLinearColor::Red;
	}
}

void UNBDebugMsgManagerSubSystem::PrintDebugMsg(const UObject* WorldContextObject, const FString& Msg, const ENBMsgType MsgType)
{
	if (!WorldContextObject)
	{
		return;
	}

	if (!WorldContextObject->GetWorld())
	{
		return;
	}
	
	UNBDebugMsgManagerSubSystem* MsgSubSystem = WorldContextObject->GetWorld()->GetSubsystem<UNBDebugMsgManagerSubSystem>();
	if (!MsgSubSystem)
	{
		return;
	}
	
	MsgSubSystem->PrintWorldDebugMsg(WorldContextObject, Msg, MsgType);
}

void UNBDebugMsgManagerSubSystem::PrintWorldDebugMsg(const UObject* MsgOwner, const FString& Msg, const ENBMsgType MsgType)
{
	if (CVarShowDebug.GetValueOnAnyThread() <= 0)
	{
		return;
	}

	const FString& FinalMsg = (CVarShowDebugOwner.GetValueOnAnyThread() ? GetNameSafe(MsgOwner) : "") + Msg;
	UKismetSystemLibrary::PrintString(MsgOwner,
		FinalMsg,
		false,
		true,
		GetColorFromType(MsgType)
		);

	switch (MsgType)
	{
	case ENBMsgType::Log:
		UE_CLOG(CVarShowDebugOnScreen.GetValueOnAnyThread() > 0, LogTemp, Log, TEXT("UNBDebugMsgManagerSubSystem %s"), *FinalMsg);
		break;
	case ENBMsgType::Warning:
		UE_CLOG(CVarShowDebugOnScreen.GetValueOnAnyThread() > 0, LogTemp, Warning, TEXT("UNBDebugMsgManagerSubSystem %s"), *FinalMsg);
		break;
	default:
		UE_CLOG(CVarShowDebugOnScreen.GetValueOnAnyThread() > 0, LogTemp, Error, TEXT("UNBDebugMsgManagerSubSystem %s"), *FinalMsg);
		break;
	}
}


