// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheresNoBugHere/Public/System/NBPlayerCameraManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNBPlayerCameraManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_ANBPlayerCameraManager();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_ANBPlayerCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_TheresNoBugHere();
// End Cross Module References

// Begin Class ANBPlayerCameraManager
void ANBPlayerCameraManager::StaticRegisterNativesANBPlayerCameraManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANBPlayerCameraManager);
UClass* Z_Construct_UClass_ANBPlayerCameraManager_NoRegister()
{
	return ANBPlayerCameraManager::StaticClass();
}
struct Z_Construct_UClass_ANBPlayerCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "System/NBPlayerCameraManager.h" },
		{ "ModuleRelativePath", "Public/System/NBPlayerCameraManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControlledPawn_MetaData[] = {
		{ "ModuleRelativePath", "Public/System/NBPlayerCameraManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ControlledPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANBPlayerCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANBPlayerCameraManager_Statics::NewProp_ControlledPawn = { "ControlledPawn", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANBPlayerCameraManager, ControlledPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControlledPawn_MetaData), NewProp_ControlledPawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANBPlayerCameraManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANBPlayerCameraManager_Statics::NewProp_ControlledPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANBPlayerCameraManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANBPlayerCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANBPlayerCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANBPlayerCameraManager_Statics::ClassParams = {
	&ANBPlayerCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ANBPlayerCameraManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ANBPlayerCameraManager_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANBPlayerCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ANBPlayerCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANBPlayerCameraManager()
{
	if (!Z_Registration_Info_UClass_ANBPlayerCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANBPlayerCameraManager.OuterSingleton, Z_Construct_UClass_ANBPlayerCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANBPlayerCameraManager.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<ANBPlayerCameraManager>()
{
	return ANBPlayerCameraManager::StaticClass();
}
ANBPlayerCameraManager::ANBPlayerCameraManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANBPlayerCameraManager);
ANBPlayerCameraManager::~ANBPlayerCameraManager() {}
// End Class ANBPlayerCameraManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBPlayerCameraManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANBPlayerCameraManager, ANBPlayerCameraManager::StaticClass, TEXT("ANBPlayerCameraManager"), &Z_Registration_Info_UClass_ANBPlayerCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANBPlayerCameraManager), 829346239U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBPlayerCameraManager_h_1884417926(TEXT("/Script/TheresNoBugHere"),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBPlayerCameraManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBPlayerCameraManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
