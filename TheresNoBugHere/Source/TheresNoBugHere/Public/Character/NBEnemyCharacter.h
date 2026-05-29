// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NBBaseCharacter.h"
#include "NBEnemyCharacter.generated.h"

UCLASS()
class THERESNOBUGHERE_API ANBEnemyCharacter : public ANBBaseCharacter
{
	GENERATED_BODY()

public:
	ANBEnemyCharacter();

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
};
