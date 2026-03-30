// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/NBAnimInstanceBase.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UNBAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	const ACharacter* Character = Cast<ACharacter>(GetOwningActor());
	if (!Character)
	{
		return;
	}

	const UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();

	LocalMotionData.bInAir = MovementComponent->IsFalling();
	LocalMotionData.MovingVelocitySize = MovementComponent->Velocity.Size2D();
	LocalMotionData.bIsMoving = LocalMotionData.MovingVelocitySize > 1.f && MovementComponent->GetCurrentAcceleration().SizeSquared2D() > 1.f;
	LocalMotionData.MovingDirectionAngle = 0.f;
	if (LocalMotionData.bIsMoving)
	{
		const FVector FacingDirection = Character->GetActorRotation().Vector();
		const FVector MoveDirection = MovementComponent->Velocity.GetSafeNormal();
		const float Angle = UKismetMathLibrary::DegAcos(FVector::DotProduct(FacingDirection, MoveDirection));
		const float Sign = FVector::CrossProduct(FacingDirection, MoveDirection).Z;
		LocalMotionData.MovingDirectionAngle = Angle * FMath::Sign(FMath::IsNearlyEqual(Sign, 0.f) ? 1.f : Sign);
	}

}
