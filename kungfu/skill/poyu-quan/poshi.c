// poshi.c 破石一击

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "破石"ZJBR"一击"; }
string *pfm_type() { return ({ "cuff", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if (! target || ! me->is_fighting(target))
		return notify_fail("「破石一击」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("poyu-quan", 1) < 120)
		return notify_fail("你的破玉拳不够娴熟，不会使用「破石一击」。\n");
				
	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功修为还不够高，难以运用「破石一击」。\n");
			
	if ((int)me->query("neili") < 300)
		return notify_fail("你现在真气不够，不能使用「破石一击」。\n");

	if (me->query_skill_mapped("cuff") != "poyu-quan")
		return notify_fail("你没有激发破玉拳，不能使用「破石一击」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "大喝一声，拳头如闪电一般重重的击向$n" HIY "。"NOR"\n";

	ap = me->query_skill("force") + me->query_str() * 10;
	dp = target->query_skill("force") + target->query_str() * 10;
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + (int)me->query_skill("cuff");
		damage = damage / 5;
		damage += random(damage);

		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "只见$P" HIR "这一拳把$p" HIR
					   "打飞了出去，重重的摔在地上，吐血不止！"NOR"\n");
		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "奋力招架，硬生生的挡开了$P"
		       HIC "这一招。"NOR"\n";
		me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
