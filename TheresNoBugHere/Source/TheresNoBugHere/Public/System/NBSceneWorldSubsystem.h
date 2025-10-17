// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/NBMapDataActor.h"
#include "Subsystems/WorldSubsystem.h"
#include "NBSceneWorldSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UNBSceneWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	void RegisterMapData(ANBMapDataActor* InMapDataActor);

	UFUNCTION(Blueprintable)
	FVector TryWorldLimit(const FVector& InLocation) const;

	UFUNCTION(Blueprintable)
	FVector TryCameraLimit(const FVector& InLocation) const;
	
public:
	UPROPERTY()
	TObjectPtr<ANBMapDataActor> MapDataActor;
};
