// san.c 天女散花

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "天女"ZJBR"散花"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("天女散花只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("sanhua-zhang", 1) < 135)
		return notify_fail("你的散花掌法不够娴熟，不会使用天女散花。\n");

	if ((int)me->query_skill("force") < 180)
		return notify_fail("你的内功修为不够，难以施展天女散花。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你现在真气不够，无法使用天女散花。\n");

	if (me->query_skill_mapped("strike") != "sanhua-zhang") 
		return notify_fail("你没有激发散花掌，无法使用天女散花！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "哈哈一笑，双掌一错，忽然化作漫天"
	      "掌影，犹如千百只手掌一齐攻向$n" HIY "！"NOR"\n";

	if (random(me->query_skill("strike")) > target->query_skill("dodge") / 2)
	{
		me->start_busy(2);
		damage = me->query_skill("strike");
		damage = damage / 2 + random(damage / 2);
		me->add("neili", -150);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "结果$p" HIR "没能避开$P" HIR
					   "变幻莫测的掌法，蓬蓬接连中了数掌，"
					   "被打得口喷鲜血，几乎摔倒！"NOR"\n");
	} else
	{
		me->start_busy(3);
		me->add("neili", -50);
		msg += CYN "可是$p" CYN "识破了$P"
		       CYN "这一招，斜斜一跃避开。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
