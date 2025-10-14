// Fill out your copyright notice in the Description page of Project Settings.


#include "System/NBSceneWorldSubsystem.h"

#include "Config/NBCameraSettings.h"
#include "Kismet/GameplayStatics.h"
#include "System/NBGameInstance.h"

bool UNBSceneWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
	//const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
	//return SceneSettings;
}

void UNBSceneWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UNBGameInstance* GameInstance = Cast<UNBGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (GameInstance)
	{
		 GameInstance->GetCurrentMapData(CurrentMapData);
	}
}
