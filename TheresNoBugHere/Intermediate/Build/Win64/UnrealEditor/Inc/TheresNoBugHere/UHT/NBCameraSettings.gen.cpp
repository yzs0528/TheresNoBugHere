// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheresNoBugHere/Public/Config/NBCameraSettings.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNBCameraSettings() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBCameraSettings();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBCameraSettings_NoRegister();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBSceneSettings();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBSceneSettings_NoRegister();
THERESNOBUGHERE_API UScriptStruct* Z_Construct_UScriptStruct_FNBMapData();
UPackage* Z_Construct_UPackage__Script_TheresNoBugHere();
// End Cross Module References

// Begin ScriptStruct FNBMapData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_NBMapData;
class UScriptStruct* FNBMapData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_NBMapData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_NBMapData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNBMapData, (UObject*)Z_Construct_UPackage__Script_TheresNoBugHere(), TEXT("NBMapData"));
	}
	return Z_Registration_Info_UScriptStruct_NBMapData.OuterSingleton;
}
template<> THERESNOBUGHERE_API UScriptStruct* StaticStruct<FNBMapData>()
{
	return FNBMapData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FNBMapData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelName_MetaData[] = {
		{ "Category", "NBMapData" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraLimit_MetaData[] = {
		{ "Category", "NBMapData" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementLimit_MetaData[] = {
		{ "Category", "NBMapData" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_LevelName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraLimit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementLimit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNBMapData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FNBMapData_Statics::NewProp_LevelName = { "LevelName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNBMapData, LevelName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelName_MetaData), NewProp_LevelName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FNBMapData_Statics::NewProp_CameraLimit = { "CameraLimit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNBMapData, CameraLimit), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraLimit_MetaData), NewProp_CameraLimit_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FNBMapData_Statics::NewProp_MovementLimit = { "MovementLimit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNBMapData, MovementLimit), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementLimit_MetaData), NewProp_MovementLimit_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNBMapData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNBMapData_Statics::NewProp_LevelName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNBMapData_Statics::NewProp_CameraLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNBMapData_Statics::NewProp_MovementLimit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNBMapData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNBMapData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
	nullptr,
	&NewStructOps,
	"NBMapData",
	Z_Construct_UScriptStruct_FNBMapData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNBMapData_Statics::PropPointers),
	sizeof(FNBMapData),
	alignof(FNBMapData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNBMapData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNBMapData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FNBMapData()
{
	if (!Z_Registration_Info_UScriptStruct_NBMapData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_NBMapData.InnerSingleton, Z_Construct_UScriptStruct_FNBMapData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_NBMapData.InnerSingleton;
}
// End ScriptStruct FNBMapData

// Begin Class UNBCameraSettings
void UNBCameraSettings::StaticRegisterNativesUNBCameraSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNBCameraSettings);
UClass* Z_Construct_UClass_UNBCameraSettings_NoRegister()
{
	return UNBCameraSettings::StaticClass();
}
struct Z_Construct_UClass_UNBCameraSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Config/NBCameraSettings.h" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraLength_MetaData[] = {
		{ "Category", "CameraSettings" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraLength;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNBCameraSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNBCameraSettings_Statics::NewProp_CameraLength = { "CameraLength", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNBCameraSettings, CameraLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraLength_MetaData), NewProp_CameraLength_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNBCameraSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNBCameraSettings_Statics::NewProp_CameraLength,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBCameraSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNBCameraSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBCameraSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNBCameraSettings_Statics::ClassParams = {
	&UNBCameraSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UNBCameraSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UNBCameraSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNBCameraSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UNBCameraSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNBCameraSettings()
{
	if (!Z_Registration_Info_UClass_UNBCameraSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNBCameraSettings.OuterSingleton, Z_Construct_UClass_UNBCameraSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNBCameraSettings.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<UNBCameraSettings>()
{
	return UNBCameraSettings::StaticClass();
}
UNBCameraSettings::UNBCameraSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNBCameraSettings);
UNBCameraSettings::~UNBCameraSettings() {}
// End Class UNBCameraSettings

// Begin Class UNBSceneSettings
void UNBSceneSettings::StaticRegisterNativesUNBSceneSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNBSceneSettings);
UClass* Z_Construct_UClass_UNBSceneSettings_NoRegister()
{
	return UNBSceneSettings::StaticClass();
}
struct Z_Construct_UClass_UNBSceneSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Config/NBCameraSettings.h" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MapData_MetaData[] = {
		{ "Category", "CameraSettings" },
		{ "ModuleRelativePath", "Public/Config/NBCameraSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MapData_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MapData_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_MapData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNBSceneSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UNBSceneSettings_Statics::NewProp_MapData_ValueProp = { "MapData", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FNBMapData, METADATA_PARAMS(0, nullptr) }; // 2578654574
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UNBSceneSettings_Statics::NewProp_MapData_Key_KeyProp = { "MapData_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UNBSceneSettings_Statics::NewProp_MapData = { "MapData", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNBSceneSettings, MapData), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MapData_MetaData), NewProp_MapData_MetaData) }; // 1298103297 2578654574
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNBSceneSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNBSceneSettings_Statics::NewProp_MapData_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNBSceneSettings_Statics::NewProp_MapData_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNBSceneSettings_Statics::NewProp_MapData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBSceneSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNBSceneSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBSceneSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNBSceneSettings_Statics::ClassParams = {
	&UNBSceneSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UNBSceneSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UNBSceneSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNBSceneSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UNBSceneSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNBSceneSettings()
{
	if (!Z_Registration_Info_UClass_UNBSceneSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNBSceneSettings.OuterSingleton, Z_Construct_UClass_UNBSceneSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNBSceneSettings.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<UNBSceneSettings>()
{
	return UNBSceneSettings::StaticClass();
}
UNBSceneSettings::UNBSceneSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNBSceneSettings);
UNBSceneSettings::~UNBSceneSettings() {}
// End Class UNBSceneSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Config_NBCameraSettings_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FNBMapData::StaticStruct, Z_Construct_UScriptStruct_FNBMapData_Statics::NewStructOps, TEXT("NBMapData"), &Z_Registration_Info_UScriptStruct_NBMapData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNBMapData), 2578654574U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNBCameraSettings, UNBCameraSettings::StaticClass, TEXT("UNBCameraSettings"), &Z_Registration_Info_UClass_UNBCameraSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNBCameraSettings), 1665867792U) },
		{ Z_Construct_UClass_UNBSceneSettings, UNBSceneSettings::StaticClass, TEXT("UNBSceneSettings"), &Z_Registration_Info_UClass_UNBSceneSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNBSceneSettings), 4053214826U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Config_NBCameraSettings_h_3535675332(TEXT("/Script/TheresNoBugHere"),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Config_NBCameraSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Config_NBCameraSettings_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Config_NBCameraSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Config_NBCameraSettings_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
