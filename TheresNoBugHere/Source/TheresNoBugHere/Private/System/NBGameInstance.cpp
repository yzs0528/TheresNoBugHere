// Fill out your copyright notice in the Description page of Project Settings.


#include "System/NBGameInstance.h"

#include "Config/NBCameraSettings.h"
#include "Kismet/GameplayStatics.h"

void UNBGameInstance::Init()
{
	Super::Init();

	CurrentMapTag = FGameplayTag::EmptyTag;
}

void UNBGameInstance::OpenLevelByTag(FGameplayTag InMapTag)
{
	const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
	if (const FNBMapData* MapData = SceneSettings->MapData.Find(InMapTag))
	{
		UGameplayStatics::OpenLevel(this, MapData->LevelName);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("OpenLevelByTag Can't Find Level Data By Tag:%s"), *InMapTag.ToString());
	}
}

void UNBGameInstance::GetCurrentMapData(FNBMapData& OutMapData)
{
	const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
	if (const FNBMapData* MapData = SceneSettings->MapData.Find(CurrentMapTag))
	{
		OutMapData = *MapData;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("GetCurrentMapData Can't Find Level Data By Tag:%s"), *CurrentMapTag.ToString());
	}
}
