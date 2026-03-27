// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/NBAnimInstanceBase.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UNBAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	const ACharacter* Character = Cast<ACharacter>(GetOwningActor());
	if (!Character)
	{
		return;
	}

	const UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();

	bInAir = MovementComponent->IsFalling();
	bIsMoving = MovementComponent->Velocity.SizeSquared2D() > 1.f && MovementComponent->GetCurrentAcceleration().SizeSquared2D() > 1.f;
}
