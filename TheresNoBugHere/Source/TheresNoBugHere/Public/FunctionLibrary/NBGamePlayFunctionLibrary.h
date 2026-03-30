// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NBGamePlayFunctionLibrary.generated.h"

class UNBCharacterStateComponent;
struct FGameplayTag;
/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API UNBGamePlayFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Input")
	static FVector InputDirectionToWorldDirection(const FVector2D& InputDirection, const FRotator& BaseRotation);

	UFUNCTION(BlueprintPure, Category = "Input", DisplayName = "HasMovementInput")
	static bool ActorHasMovementInput(AActor* OwningActor);

	UFUNCTION(BlueprintPure, Category = "Input", DisplayName = "HasMovementInput")
	static bool ControllerHasMovementInput(AController* OwningController);
	
	UFUNCTION(BlueprintPure, Category = "Input")
	static FVector2D GetLastMovementInput(AActor* OwningActor);

	UFUNCTION(BlueprintPure, Category = "Input")
	static FVector GetLastMovementWorldDirection(AActor* OwningActor);

	// State
	UFUNCTION(BlueprintPure, Category = "State")
	static UNBCharacterStateComponent* GetCharacterStateComponent(AActor* OwningActor);
	
	UFUNCTION(BlueprintCallable, Category = "State", Meta = (Categories = "NB_Tags.State"))
	static void AddStateTag(AActor* OwningActor, FGameplayTag InTag);

	UFUNCTION(BlueprintCallable, Category = "State", Meta = (Categories = "NB_Tags.State"))
	static void RemoveStateTag(AActor* OwningActor, FGameplayTag InTag);
};
