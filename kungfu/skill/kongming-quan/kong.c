// kong.c 空明拳空空如也

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "空空"ZJBR"如也"; }
string *pfm_type() { return ({ "unarmed", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("空空如也只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「空空如也」！\n");		
		
	if ((int)me->query_skill("kongming-quan", 1) < 125)
		return notify_fail("你的空明拳不够娴熟，不会使用「空空如也」。\n");
				
	if ((int)me->query("neili", 1) < 150)
		return notify_fail("你现在真气太弱，难以使用「空空如也」。\n");

	if (me->query_skill_mapped("unarmed") != "kongming-quan")
		return notify_fail("你没有激发空明拳，不能使用「空空如也」。");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = CYN "$N" CYN "使出空明拳「空空如也」，拳劲变化莫测，让$n"
	      CYN "一时难以捕捉。"NOR"\n";
	me->add("neili", -80);

	ap = me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query_skill("parry") + target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(3);
		
		damage = ap / 2 + random(ap / 2);
		
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK,
					   damage, 48,
					   CYN "$n实在无法窥测$N" CYN
					   "这一拳的劲力，被$P"
					   CYN "这一拳正好打中！\n"
					   ":内伤@?");
	} else 
	{
		me->start_busy(2);
		msg += CYN "可是$p" CYN "识破了$P"
		       CYN "的拳招中的变化，精心应对，并没有吃亏。"NOR"\n";
	}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
