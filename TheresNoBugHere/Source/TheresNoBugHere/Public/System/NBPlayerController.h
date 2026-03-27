// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "NBPlayerController.generated.h"

struct FGameplayTag;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class THERESNOBUGHERE_API ANBPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void SetupInputComponent() override;

public:
	void ActiveAbility(const FGameplayTag& AbilityTag) const;
	
public:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void Action_DefaultAttack(const FInputActionValue& Value);
	void Action_Dash(const FInputActionValue& Value);
	void Action_Ability01(const FInputActionValue& Value);
	void Action_Ability02(const FInputActionValue& Value);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|MappingContext")
	TArray<TObjectPtr<UInputMappingContext>> MappingContexts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|InputAction|Defalut")
	TObjectPtr<UInputAction> InputAction_Move;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|InputAction|Defalut")
	TObjectPtr<UInputAction> InputAction_Look;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|InputAction|Ability")
	TObjectPtr<UInputAction> InputAction_DefaultAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|InputAction|Ability")
	TObjectPtr<UInputAction> InputAction_Dash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|InputAction|Ability")
	TObjectPtr<UInputAction> InputAction_Ability01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|InputAction|Ability")
	TObjectPtr<UInputAction> InputAction_Ability02;
};
