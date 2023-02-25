// guanghua.c

#include <ansi.h>
#include <combat.h>

#define GUANG "「" HIY "光华令" NOR "」"

inherit F_SSERVER;

string query_name() { return "光华令"; }

int perform(object me, object target)
{
	object weapon;
	int damage, skill;
	string msg;

	if (! target) target = offensive_target(me);

	skill = me->query_skill("shenghuo-ling",1);

	if (! (me->is_fighting()))
		return notify_fail(GUANG "只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用的兵器不对，不能使用圣火令法之" GUANG "。\n");

	if (skill < 140)
		return notify_fail("你的圣火令法等级不够, 不能使用圣火令法之" GUANG "。\n");

	if (me->query("max_neili") < 1500)
		return notify_fail("你的内力修为不足，不能使用圣火令法之" GUANG "。\n");

	if (me->query("neili") < 300)
		return notify_fail("你的内力不够，不能使用圣火令法之" GUANG "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "猛吸一口气，使出圣火令法之光华令，手中"
	      + weapon->name() + NOR + HIY "御驾如飞，幻出无数道金"
	      "芒，将$n" HIY "笼罩起来！"NOR"\n";

	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		damage = skill / 3 + me->query_skill("force") / 3;
		damage += random(damage);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
		       HIR "$n" HIR "只觉万道金芒铺天盖地席卷而来，"
		       "完全无法阻挡。顿时只感全身几处刺痛，鲜血飞"
		       "溅而出！"NOR"\n");

		me->start_busy(2);
	} else
	{
		msg += CYN "可是$n" CYN "看准$N" CYN "的破绽，猛地向"
		       "前一跃，跳出了$N" CYN "的攻击范围。"NOR"\n";
		me->add("neili", -50);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
