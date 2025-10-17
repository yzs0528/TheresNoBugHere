// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NBMapDataActor.generated.h"

USTRUCT(BlueprintType)
struct FNBMapData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D CameraLimitY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D CameraLimitZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MovementLimitY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MovementLimitZ;
};

UCLASS()
class THERESNOBUGHERE_API ANBMapDataActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBMapDataActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateData();
	FVector TryWorldLimit(const FVector& InLocation);
	FVector TryCameraLimit(const FVector& InLocation);

	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNBMapData MapData;
	
	FVector2D WorldSpaceLimitY;
	FVector2D WorldSpaceLimitZ;
	
	FVector2D WorldSpaceCameraLimitY;
	FVector2D WorldSpaceCameraLimitZ;
};
