#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace NB_Tags
{
	/**
	 * 角色状态 Tag
	 * 配合 UNBCharacterStateComponent 使用，通过引用计数管理
	 *
	 * 命名规范：NB_Tags.State.XXX
	 */
	namespace State
	{
		/** 阻断所有玩家输入（移动、技能、视角等） */
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlockInput);

		/** 阻断移动输入 */
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlockMove);

		/** 阻断技能输入 */
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(BlockAbility);

		/** 无敌状态（不受伤害） */
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Invincible);

		/** 硬直/受击状态 */
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Stagger);

		/** 死亡状态 */
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dead);
	}

	namespace Abilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(DefaultAttack);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dash);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability01);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability02);
	}

	namespace Animation
	{
		// Sequence
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Idle);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(SpecialIdle);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(BattleIdle);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(JumpStart);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Falling);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(OnLand);
		
		// Blend Space
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(MoveBlendSpace);
		//UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability02);
		
		// Montage
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(DefaultAttack01);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(DefaultAttack02);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(DefaultAttack03);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dash);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability01);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability02);
	}
}
