// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "NBMapDataActor.generated.h"

class UBehaviorTree;

USTRUCT(BlueprintType)
struct FNBMapData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MapName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D CameraLimitY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D CameraLimitZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MovementLimitY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MovementLimitZ;
};

UENUM()
enum class EDynamicNavigationBlockType
{
	DefaultMap,
	PlayerBlocked,
	DynamicBlock,
};

USTRUCT(BlueprintType)
struct FDynamicNavigationData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NavBlockData = 0;
};

USTRUCT(BlueprintType, BlueprintType)
struct FDefaultMapNavigationData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint CellIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasBlocked = false;
};

UCLASS()
class THERESNOBUGHERE_API ANBMapDataActor : public AInfo
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
	UDataTable* FindMapNavigationDataTable(bool CreateIfNotFound);

	UFUNCTION(Blueprintable, CallInEditor)
	void GeneralDefaultMapData();

	UFUNCTION(Blueprintable)
	bool GetNavPointsByLocation(const FVector& StartLocation, const FVector& EndLocation, TArray<FVector>& OutPathPoints);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNBMapData MapData;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FIntPoint, int32> MapNavigationData;

protected:
	FVector2D WorldSpaceLimitY;
	FVector2D WorldSpaceLimitZ;
	
	FVector2D WorldSpaceCameraLimitY;
	FVector2D WorldSpaceCameraLimitZ;
};
