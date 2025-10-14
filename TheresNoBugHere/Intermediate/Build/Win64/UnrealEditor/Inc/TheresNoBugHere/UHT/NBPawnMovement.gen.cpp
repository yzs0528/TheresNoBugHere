// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheresNoBugHere/Public/Component/NBPawnMovement.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNBPawnMovement() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBPawnMovement();
THERESNOBUGHERE_API UClass* Z_Construct_UClass_UNBPawnMovement_NoRegister();
UPackage* Z_Construct_UPackage__Script_TheresNoBugHere();
// End Cross Module References

// Begin Class UNBPawnMovement
void UNBPawnMovement::StaticRegisterNativesUNBPawnMovement()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNBPawnMovement);
UClass* Z_Construct_UClass_UNBPawnMovement_NoRegister()
{
	return UNBPawnMovement::StaticClass();
}
struct Z_Construct_UClass_UNBPawnMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Component/NBPawnMovement.h" },
		{ "ModuleRelativePath", "Public/Component/NBPawnMovement.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNBPawnMovement>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UNBPawnMovement_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFloatingPawnMovement,
	(UObject* (*)())Z_Construct_UPackage__Script_TheresNoBugHere,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNBPawnMovement_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNBPawnMovement_Statics::ClassParams = {
	&UNBPawnMovement::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNBPawnMovement_Statics::Class_MetaDataParams), Z_Construct_UClass_UNBPawnMovement_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNBPawnMovement()
{
	if (!Z_Registration_Info_UClass_UNBPawnMovement.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNBPawnMovement.OuterSingleton, Z_Construct_UClass_UNBPawnMovement_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNBPawnMovement.OuterSingleton;
}
template<> THERESNOBUGHERE_API UClass* StaticClass<UNBPawnMovement>()
{
	return UNBPawnMovement::StaticClass();
}
UNBPawnMovement::UNBPawnMovement(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNBPawnMovement);
UNBPawnMovement::~UNBPawnMovement() {}
// End Class UNBPawnMovement

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Component_NBPawnMovement_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNBPawnMovement, UNBPawnMovement::StaticClass, TEXT("UNBPawnMovement"), &Z_Registration_Info_UClass_UNBPawnMovement, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNBPawnMovement), 3334528642U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Component_NBPawnMovement_h_2341909457(TEXT("/Script/TheresNoBugHere"),
	Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Component_NBPawnMovement_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_TheresNoBugHere_TheresNoBugHere_TheresNoBugHere_Source_TheresNoBugHere_Public_Component_NBPawnMovement_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
