// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NBAnimationData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FNBAnimSetData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Categories = "NB_Tags.Animation"))
	FGameplayTag AnimTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<UAnimationAsset> AnimAsset;

	bool operator==(const FNBAnimSetData& Other) const
	{
		return AnimTag == Other.AnimTag && AnimAsset == Other.AnimAsset;
	}
};

USTRUCT(BlueprintType)
struct FNBRuntimeAnimSetData
{
	GENERATED_BODY()

public:
	void UpdateAnimSet(TObjectPtr<UAnimationAsset> InAnimAsset)
	{
		if (AnimAsset == InAnimAsset)
		{
			return;
		}
		
		AnimAsset = InAnimAsset;
		Version++;
	}

	bool IsValid() const
	{
		return Version > 0 && AnimAsset->IsValidLowLevelFast();
	}
	
	int32 GetVersion() const { return Version; }
	
	template <typename T>
	T* GetAnimAsset() { return Cast<T>(AnimAsset); }
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAnimationAsset> AnimAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Version = 0;
	
public:
	bool operator==(const FNBRuntimeAnimSetData& Other) const
	{
		return AnimAsset == Other.AnimAsset;
	}
};


USTRUCT(BlueprintType)
struct FNBAvatarData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AvatarID = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<USkeletalMesh> Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UAnimInstance> AnimInstanceClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UAnimInstance>> OverrideLayers;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TAssetPtr<UDataTable> AnimSetTable;
};


USTRUCT(BlueprintType)
struct FNBAnimData_LocalMotion
{
	
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	bool bInAir = false;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	bool bIsMoving = false;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float MovingVelocitySize = 0.f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float MovingDirectionAngle = 0.f;
};
