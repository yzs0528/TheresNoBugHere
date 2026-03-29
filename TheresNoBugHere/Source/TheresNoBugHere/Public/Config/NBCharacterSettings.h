// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "NBCharacterSettings.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, config = Game, defaultconfig)
class THERESNOBUGHERE_API UNBCharacterSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CharacterSettings")
	int32 DefaultCharacterID = 0;
	
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CharacterSettings")
	TAssetPtr<UDataTable> CharacterDataTable;
	
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere, Category = "CharacterSettings")
	TAssetPtr<UDataTable> AvatarDataTable;
	
};
