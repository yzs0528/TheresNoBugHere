// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor/NBMapDataActor.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Config/NBWorldSettings.h"
#include "System/NBSceneWorldSubsystem.h"
#include "UObject/SavePackage.h"

static TAutoConsoleVariable<int32> CVarDebugWorldLimit(
	TEXT("NB.ShouldDebugWorldLimit"),
	0,
	TEXT("1 To Draw Limit"));

static TAutoConsoleVariable<int32> CVarDebugNavCollision(
	TEXT("NB.ShouldDebugNavCollision"),
	0,
	TEXT("1 To Draw Block"));

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

	if (CVarDebugNavCollision.GetValueOnAnyThread() > 0)
	{
		const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
		if (!SceneSettings)
		{
			return;
		}
		
		for (const auto& NavData : MapNavigationData)
		{
			if (NavData.Value <= 0)
			{
				continue;
			}

			const float MapCellLength = SceneSettings->MapCellLength;
			const FVector WorldLocation(0.f, MapCellLength * (NavData.Key.X + 0.5f), MapCellLength * (NavData.Key.Y + 0.5f));
			UKismetSystemLibrary::DrawDebugBox(this, WorldLocation, FVector(400.f, MapCellLength * 0.5f, MapCellLength * 0.5f), FLinearColor::Red);
		}
	}
}

void ANBMapDataActor::UpdateData()
{
	const FVector& OriginLocation = GetActorLocation();
	// World Limit
	WorldSpaceLimitY = FVector2D(MapData.MovementLimitY.X + OriginLocation.Y, MapData.MovementLimitY.Y + OriginLocation.Y);
	WorldSpaceLimitZ = FVector2D(MapData.MovementLimitZ.X + OriginLocation.Z, MapData.MovementLimitZ.Y + OriginLocation.Z);

	// Camera Limit
	WorldSpaceCameraLimitY = FVector2D(MapData.CameraLimitY.X + OriginLocation.Y, MapData.CameraLimitY.Y + OriginLocation.Y);
	WorldSpaceCameraLimitZ = FVector2D(MapData.CameraLimitZ.X + OriginLocation.Z, MapData.CameraLimitZ.Y + OriginLocation.Z);

	// Navigation Data
	UDataTable* DataTable = FindMapNavigationDataTable(false);
	if (!DataTable || DataTable->RowStruct != FDefaultMapNavigationData::StaticStruct())
	{
		return;
	}
	
	for (const auto& NavData : DataTable->GetRowMap())
	{
		const FDefaultMapNavigationData* NavigationData = reinterpret_cast<FDefaultMapNavigationData*>(NavData.Value);
		MapNavigationData.FindOrAdd(NavigationData->CellIndex) = NavigationData->bHasBlocked ? 1 : 0;
	}
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

UDataTable* ANBMapDataActor::FindMapNavigationDataTable(bool CreateIfNotFound)
{
	const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
	if (!SceneSettings)
	{
		return nullptr;
	}
	
	UDataTable* DataTable = nullptr;
	const FString DTName = FString::Format(TEXT("{0}{1}"), {"DT_NavData_", MapData.MapName.ToString()});
	const FString PkgName = FString::Format(TEXT("{0}/{1}"), {SceneSettings->MapNavigationDataDir, DTName});
	if (FPackageName::DoesPackageExist(PkgName))
	{
		DataTable = LoadObject<UDataTable>(nullptr, *PkgName);
		DataTable->RowStruct = FDefaultMapNavigationData::StaticStruct();
	}
	else if (CreateIfNotFound)
	{
		UPackage* Package = CreatePackage(*PkgName);
		if (!Package)
		{
			return nullptr;
		}

		Package->FullyLoad();
		DataTable = NewObject<UDataTable>(Package, *DTName, RF_Public | RF_Standalone);
		DataTable->RowStruct = FDefaultMapNavigationData::StaticStruct();
		DataTable->SaveConfig();
		FAssetRegistryModule::AssetCreated(DataTable);
	}
	return DataTable;
}

void ANBMapDataActor::GeneralDefaultMapData()
{
	const UNBSceneSettings* SceneSettings = GetDefault<UNBSceneSettings>();
	if (!SceneSettings)
	{
		return;
	}

	const float MapCellLength = SceneSettings->MapCellLength;
	if (MapCellLength <= 0.f)
	{
		return;
	}

	if (MapData.MapName.IsNone())
	{
		return;
	}

	UDataTable* DataTable = FindMapNavigationDataTable(true);
	if (!DataTable)
	{
		return;
	}

	DataTable->Modify();
	DataTable->EmptyTable();

	UpdateData();
	TMap<FIntPoint, int32> DefaultMapNavigationData;
	
	const FIntPoint MinPoint(WorldSpaceLimitY.X / MapCellLength, WorldSpaceLimitZ.X / MapCellLength);
	const FIntPoint MaxPoint(WorldSpaceLimitY.Y / MapCellLength, WorldSpaceLimitZ.Y / MapCellLength);

	FHitResult HitResult;
	for (int32 x = MinPoint.X; x < MaxPoint.X; x++)
	{
		for (int32 y = MinPoint.Y; y < MaxPoint.Y; y++)
		{
			constexpr float TraceDeep = 300.f;
			HitResult.bBlockingHit = false;
			FVector TraceOrigin = FVector(0.f, x + 0.5f, y + 0.5f) * MapCellLength;
			FVector TraceOffset = FVector::ForwardVector * TraceDeep;
			UKismetSystemLibrary::LineTraceSingleForObjects(this, TraceOrigin, TraceOrigin - TraceOffset,
				SceneSettings->BlockTraceObjectTypes, false, {}, EDrawDebugTrace::None, HitResult, true);
			DefaultMapNavigationData.Emplace(FIntPoint(x, y)) = HitResult.bBlockingHit ? 1 : 0;

			UKismetSystemLibrary::DrawDebugBox(this, TraceOrigin, FVector(TraceDeep, MapCellLength * 0.5f, MapCellLength * 0.5f),
				HitResult.bBlockingHit ? FLinearColor::Red : FLinearColor::Green, FRotator::ZeroRotator, 0.5f);
		}
	}

	int32 RowIndex = 0;
	FDefaultMapNavigationData Data;
	for (const auto& NavData : DefaultMapNavigationData)
	{
		Data.CellIndex = NavData.Key;
		Data.bHasBlocked = NavData.Value > 0;
		DataTable->AddRow(*FString::FromInt(RowIndex++), Data);
	}

	FString PackageFileName;
	if (FPackageName::TryConvertLongPackageNameToFilename(DataTable->GetPackage()->GetName(), PackageFileName))
	{
		FString PackageAbsolutePath = FPaths::ConvertRelativePathToFull(MoveTemp(PackageFileName));
		FSavePackageArgs PackageArgs;
		PackageArgs.Error = GError;
		PackageArgs.SaveFlags = SAVE_NoError;
		PackageArgs.TopLevelFlags = EObjectFlags::RF_Standalone;
		
		UPackage::SavePackage(DataTable->GetPackage(), this, *PackageAbsolutePath, PackageArgs);
	}
}

bool ANBMapDataActor::GetNavPointsByLocation(const FVector& StartLocation, const FVector& EndLocation,
	TArray<FVector>& OutPathPoints)
{
	return false;
}

