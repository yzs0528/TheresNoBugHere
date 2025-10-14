// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheresNoBugHere/Public/System/NBSceneWorldSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNBSceneWorldSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBSceneWorldSubsystem();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBSceneWorldSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_TheresNoBugHere();
// End Cross Module References

// Begin Class UNBSceneWorldSubsystem
void UNBSceneWorldSubsystem::StaticRegisterNativesUNBSceneWorldSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNBSceneWorldSubsystem);
UClass* Z_Construct_UClass_UNBSceneWorldSubsystem_NoRegister()
{
	return UNBSceneWorldSubsystem::StaticClass();
}
struct Z_Construct_UClass_UNBSceneWorldSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "System/NBSceneWorldSubsystem.h" },
		{ "ModuleRelativePath", "Public/System/NBSceneWorldSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNBSceneWorldSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UNBSceneWorldSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBSceneWorldSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNBSceneWorldSubsystem_Statics::ClassParams = {
	&UNBSceneWorldSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNBSceneWorldSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UNBSceneWorldSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNBSceneWorldSubsystem()
{
	if (!Z_Registration_Info_UClass_UNBSceneWorldSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNBSceneWorldSubsystem.OuterSingleton, Z_Construct_UClass_UNBSceneWorldSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNBSceneWorldSubsystem.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<UNBSceneWorldSubsystem>()
{
	return UNBSceneWorldSubsystem::StaticClass();
}
UNBSceneWorldSubsystem::UNBSceneWorldSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNBSceneWorldSubsystem);
UNBSceneWorldSubsystem::~UNBSceneWorldSubsystem() {}
// End Class UNBSceneWorldSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBSceneWorldSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNBSceneWorldSubsystem, UNBSceneWorldSubsystem::StaticClass, TEXT("UNBSceneWorldSubsystem"), &Z_Registration_Info_UClass_UNBSceneWorldSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNBSceneWorldSubsystem), 1438106355U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBSceneWorldSubsystem_h_3902210733(TEXT("/Script/TheresNoBugHere"),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBSceneWorldSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBSceneWorldSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
