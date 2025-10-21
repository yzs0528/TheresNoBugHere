// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/NBSpawner.h"

#include "Config/NBWorldSettings.h"
#include "GameFramework/Character.h"
#include "Runtime/AIModule/Classes/AIController.h"

void ANBSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnDelayHandle, this, &ANBSpawner::OnSpawnDelay, SpawnDelay);
}

void ANBSpawner::OnSpawnDelay()
{
	const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
	if (!SceneSettings)
	{
		return;
	}
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	AIController = GetWorld()->SpawnActor<AAIController>(AAIController::StaticClass(), GetActorTransform(), SpawnParameters);
	if (!AIController)
	{
		return;
	}
	
	ACharacter* AICharacter = GetWorld()->SpawnActor<ACharacter>(SceneSettings->AIClass, GetActorTransform(), SpawnParameters);
	if (!AICharacter)
	{
		return;
	}

	AIController->Possess(AICharacter);
	AIController->RunBehaviorTree(BehaviorAsset);
}
