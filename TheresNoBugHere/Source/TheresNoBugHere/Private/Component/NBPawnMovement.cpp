// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/NBPawnMovement.h"

#include "System/NBSceneWorldSubsystem.h"

void UNBPawnMovement::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                    FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const UNBSceneWorldSubsystem* SceneSubSystem = GetWorld()->GetSubsystem<UNBSceneWorldSubsystem>();
	if (SceneSubSystem)
	{
		
	}
}
