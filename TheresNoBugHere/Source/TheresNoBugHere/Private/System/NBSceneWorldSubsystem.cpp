// Fill out your copyright notice in the Description page of Project Settings.


#include "System/NBSceneWorldSubsystem.h"

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
}

void UNBSceneWorldSubsystem::RegisterMapData(ANBMapDataActor* InMapDataActor)
{
	MapDataActor = InMapDataActor;
}

FVector UNBSceneWorldSubsystem::TryWorldLimit(const FVector& InLocation) const
{
	if (MapDataActor)
	{
		return MapDataActor->TryWorldLimit(InLocation);
	}

	return InLocation;
}

FVector UNBSceneWorldSubsystem::TryCameraLimit(const FVector& InLocation) const
{
	if (MapDataActor)
	{
		return MapDataActor->TryCameraLimit(InLocation);
	}

	return InLocation;
}
