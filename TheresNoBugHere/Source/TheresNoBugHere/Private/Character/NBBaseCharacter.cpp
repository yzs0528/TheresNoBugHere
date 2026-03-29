// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NBBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"
#include "Component/NBAnimManagerComponent.h"
#include "Config/NBCharacterSettings.h"
#include "Data/NBAnimationData.h"
#include "FunctionLibrary/NBAssetManagerFunctionLibrary.h"
#include "System/SubSystem/NBDebugMsgManagerSubSystem.h"


// Sets default values
ANBBaseCharacter::ANBBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AnimManagerComponent = CreateDefaultSubobject<UNBAnimManagerComponent>("AnimManagerComponent");
}

// Called when the game starts or when spawned
void ANBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitCharacter();
}


UAbilitySystemComponent* ANBBaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ANBBaseCharacter::InitCharacter()
{
	const UNBCharacterSettings* CharacterSettings = GetDefault<UNBCharacterSettings>();
	if (!CharacterSettings)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			"ANBBaseCharacter::InitCharacter, CharacterSettings is null", 
			ENBMsgType::Error);
		return;
	}
	
	if (CharacterInitID <= 0)
	{
		if (CharacterSettings->DefaultCharacterID <= 0)
		{
			UNBDebugMsgManagerSubSystem::PrintDebugMsg(this,
			"ANBBaseCharacter::InitCharacter, CharacterInitID <= 0", 
			ENBMsgType::Error);
			return;
		}
		else
		{
			CharacterInitID = CharacterSettings->DefaultCharacterID;
			UNBDebugMsgManagerSubSystem::PrintDebugMsg(this,
			"ANBBaseCharacter::InitCharacter, CharacterInitID <= 0, Replace To Default", 
			ENBMsgType::Warning);
		}
	}
	
	UDataTable* CharacterDataTable = UNBAssetManagerFunctionLibrary::SynLoadAsset<UDataTable>(this, CharacterSettings->CharacterDataTable);
	if (!CharacterDataTable)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			"ANBBaseCharacter::InitCharacter, CharacterDataTable Load Failed", 
			ENBMsgType::Error);
		return;
	}
	
	FNBCharacterData* FindCharacterData = CharacterDataTable->FindRow<FNBCharacterData>(FName(FString::FromInt(CharacterInitID)), "ANBBaseCharacter::InitCharacter");
	if (!FindCharacterData)
	{
		return;
	}
	
	CharacterData = *FindCharacterData;
	
	InitAvatar();
}

void ANBBaseCharacter::InitAvatar()
{
	if (CharacterData.AvatarID <= 0)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this,
			"ANBBaseCharacter::InitAvatar, AvatarID <= 0", 
			ENBMsgType::Error);
		return;
	}
	
	const UNBCharacterSettings* CharacterSettings = GetDefault<UNBCharacterSettings>();
	if (!CharacterSettings)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			"ANBBaseCharacter::InitAvatar, CharacterSettings is null", 
			ENBMsgType::Error);
		return;
	}

	UDataTable* AvatarDataTable = UNBAssetManagerFunctionLibrary::SynLoadAsset<UDataTable>(this, CharacterSettings->AvatarDataTable);
	if (!AvatarDataTable)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			"ANBBaseCharacter::InitAvatar, AvatarDataTable Load Failed", 
			ENBMsgType::Error);
		return;
	}

	const FNBAvatarData* AvatarData = AvatarDataTable->FindRow<FNBAvatarData>(FName(FString::FromInt(CharacterData.AvatarID)), "ANBBaseCharacter::InitAvatar");
	if (!AvatarData)
	{
		return;
	}
	
	USkeletalMesh* AvatarMesh = UNBAssetManagerFunctionLibrary::SynLoadAsset<USkeletalMesh>(this, AvatarData->Mesh);
	if (!AvatarMesh)
	{
		UNBDebugMsgManagerSubSystem::PrintDebugMsg(this, 
			"ANBBaseCharacter::InitAvatar, AvatarData Mesh Load Failed", 
			ENBMsgType::Error);
		return;
	}
	
	if (ensure(GetMesh()))
	{
		GetMesh()->SetSkeletalMesh(AvatarMesh);
		GetMesh()->SetAnimInstanceClass(AvatarData->AnimInstanceClass);

		for (const auto& AnimLayer : AvatarData->OverrideLayers)
		{
			GetMesh()->LinkAnimClassLayers(AnimLayer);
		}
	}

	UDataTable* AnimSetTable = UNBAssetManagerFunctionLibrary::SynLoadAsset<UDataTable>(this, AvatarData->AnimSetTable);
	AnimManagerComponent->InitAnimSetByTable(AnimSetTable);
}

void ANBBaseCharacter::GiveDefaultAbilities()
{
	UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponent();
	if (!AbilitySystemComponent)
	{
		return;
	}
	
	for (const auto& Ability : DefaultAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

