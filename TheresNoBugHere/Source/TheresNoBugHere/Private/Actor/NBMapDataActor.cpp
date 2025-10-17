// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetSystemLibrary.h"
#include "Actor/NBMapDataActor.h"

#include "System/NBSceneWorldSubsystem.h"

static TAutoConsoleVariable<int32> CVarDebugWorldLimit(
	TEXT("ShouldDebugWorldLimit"),
	0,
	TEXT("1 To Draw Limit"));

// Sets default values
ANBMapDataActor::ANBMapDataActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* ActorRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(ActorRootComponent);
}

// Called when the game starts or when spawned
void ANBMapDataActor::BeginPlay()
{
	Super::BeginPlay();

	UpdateData();
	
	if (GetWorld())
	{
		if (UNBSceneWorldSubsystem* SceneWorldSubsystem = GetWorld()->GetSubsystem<UNBSceneWorldSubsystem>())
		{
			SceneWorldSubsystem->RegisterMapData(this);
		}
	}
}

// Called every frame
void ANBMapDataActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CVarDebugWorldLimit.GetValueOnAnyThread() > 0)
	{
		UpdateData();
		const FVector WorldLimitExtent(1.f,
		                               (WorldSpaceLimitY.Y - WorldSpaceLimitY.X) * 0.5f,
		                               (WorldSpaceLimitZ.Y - WorldSpaceLimitZ.X) * 0.5f);
		UKismetSystemLibrary::DrawDebugBox(this,
			FVector(GetActorLocation().X, WorldSpaceLimitY.X + WorldLimitExtent.Y, WorldSpaceLimitZ.X + WorldLimitExtent.Z),
			WorldLimitExtent, FLinearColor::Red);

		const FVector CameraLimitExtent(1.f,
									   (WorldSpaceCameraLimitY.Y - WorldSpaceCameraLimitY.X) * 0.5f,
									   (WorldSpaceCameraLimitZ.Y - WorldSpaceCameraLimitZ.X) * 0.5f);
		UKismetSystemLibrary::DrawDebugBox(this,
			FVector(GetActorLocation().X, WorldSpaceCameraLimitY.X + CameraLimitExtent.Y, WorldSpaceCameraLimitZ.X + CameraLimitExtent.Z),
			CameraLimitExtent, FLinearColor::Red);
	}
}

void ANBMapDataActor::UpdateData()
{
	const FVector& OriginLocation = GetActorLocation();
	WorldSpaceLimitY = FVector2D(MapData.MovementLimitY.X + OriginLocation.Y, MapData.MovementLimitY.Y + OriginLocation.Y);
	WorldSpaceLimitZ = FVector2D(MapData.MovementLimitZ.X + OriginLocation.Y, MapData.MovementLimitZ.Y + OriginLocation.Y);
	
	WorldSpaceCameraLimitY = FVector2D(MapData.CameraLimitY.X + OriginLocation.Y, MapData.CameraLimitY.Y + OriginLocation.Y);
	WorldSpaceCameraLimitZ = FVector2D(MapData.CameraLimitY.X + OriginLocation.Y, MapData.CameraLimitY.Y + OriginLocation.Y);
}

FVector ANBMapDataActor::TryWorldLimit(const FVector& InLocation)
{
	FVector OutLocation = InLocation;
	OutLocation.Y = FMath::Clamp(InLocation.Y, WorldSpaceLimitY.X, WorldSpaceLimitY.Y);
	OutLocation.Z = FMath::Clamp(InLocation.Z, WorldSpaceLimitZ.X, WorldSpaceLimitZ.Y);
	return OutLocation;
}

FVector ANBMapDataActor::TryCameraLimit(const FVector& InLocation)
{
	FVector OutLocation = InLocation;
	OutLocation.Y = FMath::Clamp(InLocation.Y, WorldSpaceCameraLimitY.X, WorldSpaceCameraLimitY.Y);
	OutLocation.Z = FMath::Clamp(InLocation.Z, WorldSpaceCameraLimitZ.X, WorldSpaceCameraLimitZ.Y);
	return OutLocation;
}

