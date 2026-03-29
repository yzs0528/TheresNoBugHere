// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Data/NBCharacterData.h"
#include "GameFramework/Character.h"
#include "NBBaseCharacter.generated.h"

class UNBAnimManagerComponent;
class UGameplayAbility;

UCLASS()
class THERESNOBUGHERE_API ANBBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANBBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
public:
	UFUNCTION(Blueprintable, Exec)
	void InitCharacter();
	
	UFUNCTION(Blueprintable, Exec)
	void InitAvatar();
	
public:
	void GiveDefaultAbilities();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	int32 CharacterInitID = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	FNBCharacterData CharacterData;
	
	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

protected:
	UPROPERTY(VisibleAnywhere, Category = "AnimManager")
	TObjectPtr<UNBAnimManagerComponent> AnimManagerComponent;
};
