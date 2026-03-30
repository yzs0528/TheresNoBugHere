// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NBBaseCharacter.h"
#include "NBPlayerCharacter.generated.h"

UCLASS()
class THERESNOBUGHERE_API ANBPlayerCharacter : public ANBBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANBPlayerCharacter();

	virtual FVector2D GetLastMovementInput() override;
	virtual FVector GetLastMovementWorldDirection() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
