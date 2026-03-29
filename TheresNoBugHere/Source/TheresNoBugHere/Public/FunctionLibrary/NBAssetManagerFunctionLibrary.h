// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "System/SubSystem/NBAssetManagerSubSystem.h"
#include "System/SubSystem/NBDebugMsgManagerSubSystem.h"
#include "NBAssetManagerFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UNBAssetManagerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	template< typename T >
	static T* SynLoad(UObject* WorldObjectContext, const FSoftObjectPath& Path)
	{
		UNBAssetManagerSubSystem* AssetManagerSubSystem = UNBAssetManagerSubSystem::Get(WorldObjectContext);
		if (!AssetManagerSubSystem)
		{
			UNBDebugMsgManagerSubSystem::PrintDebugMsg(WorldObjectContext, 
			"UNBAssetManagerFunctionLibrary::SynLoad, AssetManagerSubSystem is null", 
			ENBMsgType::Error);
			return nullptr;
		}
		
		return Cast<T>(AssetManagerSubSystem->SynLoadObject(Path));
	}
	
	template< typename T >
	static T* SynLoadAsset(UObject* WorldObjectContext, const TAssetPtr<T>& Asset)
	{
		return SynLoad<T>(WorldObjectContext, Asset.ToSoftObjectPath());
	}
	
	
public:
	UFUNCTION(BlueprintCallable)
	static UObject* SyncLoadObject(UObject* WorldObjectContext, const FSoftObjectPath& Path);
};
