// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NBAssetManagerSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UNBAssetManagerSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	
public:
	static UNBAssetManagerSubSystem* Get(const UObject* ContextObject)
	{
		if (!ContextObject || !ContextObject->GetWorld())
		{
			return nullptr;
		}
		
		return ContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UNBAssetManagerSubSystem>();
	}
	
	UObject* SynLoadObject(const FSoftObjectPath& Path);
	
protected:
	FStreamableManager StreamableManager;
};
