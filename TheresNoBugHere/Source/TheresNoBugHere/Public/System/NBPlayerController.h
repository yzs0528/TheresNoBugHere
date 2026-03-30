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

	/** 检查当前 Pawn 是否处于阻断所有输入的状态 */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	bool IsInputBlocked() const;

	/** 检查当前 Pawn 是否处于阻断移动输入的状态 */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	bool IsMoveBlocked() const;

	/** 检查当前 Pawn 是否处于阻断技能输入的状态 */
	UFUNCTION(BlueprintPure, Category = "CharacterState")
	bool IsAbilityBlocked() const;
	
public:
	void Move(const FInputActionValue& Value);
	void MoveEnd(const FInputActionValue& Value);
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

public:
	bool bHasMovementInput = false;
	FVector2D LastMovementInput = FVector2D::ZeroVector;
	FVector LastMovementWorldDirection = FVector::ZeroVector;
};
