#include "GamePlayTags/NBTags.h"


namespace NB_Tags
{
	namespace Abilities
	{
		UE_DEFINE_GAMEPLAY_TAG(DefaultAttack, "NB_Tags.Abilities.DefaultAttack");
		UE_DEFINE_GAMEPLAY_TAG(Dash, "NB_Tags.Abilities.Dash");
		UE_DEFINE_GAMEPLAY_TAG(Ability01, "NB_Tags.Abilities.Ability01");
		UE_DEFINE_GAMEPLAY_TAG(Ability02, "NB_Tags.Abilities.Ability02");
	}
	
	namespace Animation
	{
		// Sequence
		UE_DEFINE_GAMEPLAY_TAG(Idle, "NB_Tags.Animation.Sequence.Idle");
		UE_DEFINE_GAMEPLAY_TAG(SpecialIdle, "NB_Tags.Animation.Sequence.SpecialIdle");
		UE_DEFINE_GAMEPLAY_TAG(BattleIdle, "NB_Tags.Animation.Sequence.BattleIdle");
		UE_DEFINE_GAMEPLAY_TAG(JumpStart, "NB_Tags.Animation.Sequence.JumpStart");
		UE_DEFINE_GAMEPLAY_TAG(Falling, "NB_Tags.Animation.Sequence.Falling");
		UE_DEFINE_GAMEPLAY_TAG(OnLand, "NB_Tags.Animation.Sequence.OnLand");
		
		// Blend Space
		UE_DEFINE_GAMEPLAY_TAG(MoveBlendSpace, "NB_Tags.Animation.BlendSpace.MoveBlendSpace");
		
		// Montage
		UE_DEFINE_GAMEPLAY_TAG(DefaultAttack01, "NB_Tags.Animation.Montage.DefaultAttack01");
		UE_DEFINE_GAMEPLAY_TAG(DefaultAttack02, "NB_Tags.Animation.Montage.DefaultAttack02");
		UE_DEFINE_GAMEPLAY_TAG(DefaultAttack03, "NB_Tags.Animation.Montage.DefaultAttack03");
		UE_DEFINE_GAMEPLAY_TAG(Dash, "NB_Tags.Animation.Montage.Dash");
		UE_DEFINE_GAMEPLAY_TAG(Ability01, "NB_Tags.Animation.Montage.Ability01");
		UE_DEFINE_GAMEPLAY_TAG(Ability02, "NB_Tags.Animation.Montage.Ability02");
	}
}