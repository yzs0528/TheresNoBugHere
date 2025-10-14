// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheresNoBugHere/Public/System/NBGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNBGameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBGameInstance();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_TheresNoBugHere();
// End Cross Module References

// Begin Class UNBGameInstance
void UNBGameInstance::StaticRegisterNativesUNBGameInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNBGameInstance);
UClass* Z_Construct_UClass_UNBGameInstance_NoRegister()
{
	return UNBGameInstance::StaticClass();
}
struct Z_Construct_UClass_UNBGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "System/NBGameInstance.h" },
		{ "ModuleRelativePath", "Public/System/NBGameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNBGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UNBGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNBGameInstance_Statics::ClassParams = {
	&UNBGameInstance::StaticClass,
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
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNBGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UNBGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNBGameInstance()
{
	if (!Z_Registration_Info_UClass_UNBGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNBGameInstance.OuterSingleton, Z_Construct_UClass_UNBGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNBGameInstance.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<UNBGameInstance>()
{
	return UNBGameInstance::StaticClass();
}
UNBGameInstance::UNBGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNBGameInstance);
UNBGameInstance::~UNBGameInstance() {}
// End Class UNBGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNBGameInstance, UNBGameInstance::StaticClass, TEXT("UNBGameInstance"), &Z_Registration_Info_UClass_UNBGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNBGameInstance), 1209192940U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBGameInstance_h_280179536(TEXT("/Script/TheresNoBugHere"),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_System_NBGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
