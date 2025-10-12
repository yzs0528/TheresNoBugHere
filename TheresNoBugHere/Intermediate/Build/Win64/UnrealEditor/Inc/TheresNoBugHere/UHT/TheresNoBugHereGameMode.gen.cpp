// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheresNoBugHere/TheresNoBugHereGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTheresNoBugHereGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_ATheresNoBugHereGameMode();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_ATheresNoBugHereGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_TheresNoBugHere();
// End Cross Module References

// Begin Class ATheresNoBugHereGameMode
void ATheresNoBugHereGameMode::StaticRegisterNativesATheresNoBugHereGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATheresNoBugHereGameMode);
UClass* Z_Construct_UClass_ATheresNoBugHereGameMode_NoRegister()
{
	return ATheresNoBugHereGameMode::StaticClass();
}
struct Z_Construct_UClass_ATheresNoBugHereGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TheresNoBugHereGameMode.h" },
		{ "ModuleRelativePath", "TheresNoBugHereGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATheresNoBugHereGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATheresNoBugHereGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATheresNoBugHereGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATheresNoBugHereGameMode_Statics::ClassParams = {
	&ATheresNoBugHereGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATheresNoBugHereGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATheresNoBugHereGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATheresNoBugHereGameMode()
{
	if (!Z_Registration_Info_UClass_ATheresNoBugHereGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATheresNoBugHereGameMode.OuterSingleton, Z_Construct_UClass_ATheresNoBugHereGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATheresNoBugHereGameMode.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<ATheresNoBugHereGameMode>()
{
	return ATheresNoBugHereGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATheresNoBugHereGameMode);
ATheresNoBugHereGameMode::~ATheresNoBugHereGameMode() {}
// End Class ATheresNoBugHereGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_TheresNoBugHereGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATheresNoBugHereGameMode, ATheresNoBugHereGameMode::StaticClass, TEXT("ATheresNoBugHereGameMode"), &Z_Registration_Info_UClass_ATheresNoBugHereGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATheresNoBugHereGameMode), 1821706359U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_TheresNoBugHereGameMode_h_73534147(TEXT("/Script/TheresNoBugHere"),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_TheresNoBugHereGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_TheresNoBugHereGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
