// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "NBDebugMsgManagerSubSystem.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ENBMsgType : uint8
{
	Log,
	Warning,
	Error,
};

UCLASS()
class THERESNOBUGHERE_API UNBDebugMsgManagerSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	static FLinearColor GetColorFromType(const ENBMsgType MsgType);
	static void PrintDebugMsg(const UObject* WorldContextObject, const FString& Msg, const ENBMsgType MsgType = ENBMsgType::Log);
	
public:
	UFUNCTION(BlueprintCallable)
	void PrintWorldDebugMsg(const UObject* MsgOwner, const FString& Msg, const ENBMsgType MsgType = ENBMsgType::Log);
	
};
