// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/NBPawnMovement.h"

#include "System/NBSceneWorldSubsystem.h"

void UNBPawnMovement::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                    FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (UpdatedComponent)
	{
		if (const UNBSceneWorldSubsystem* SceneSubSystem = GetWorld()->GetSubsystem<UNBSceneWorldSubsystem>())
		{
			UpdatedComponent->SetWorldLocation(SceneSubSystem->TryWorldLimit(UpdatedComponent->GetComponentLocation()));
		}
	}
}

bool UNBPawnMovement::MoveUpdatedComponentImpl(const FVector& Delta, const FQuat& NewRotation, bool bSweep,
	FHitResult* OutHit, ETeleportType Teleport)
{
	if (Super::MoveUpdatedComponentImpl(Delta, NewRotation, bSweep, OutHit, Teleport))
	{
		return true;
	}

	return false;
}
