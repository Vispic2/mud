// zhen.c 太极拳「震」字诀

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "震字诀"; }
string *pfm_type() { return ({ "unarmed", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("神功震敌只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「震」字诀！\n");		
		
	if ((int)me->query_skill("taiji-quan", 1) < 50)
		return notify_fail("你的太极拳不够娴熟，不会使用「震」字诀。\n");
				
	if ((int)me->query("neili", 1) < 100)
		return notify_fail("你现在真气太弱，不能使用「震」字诀。\n");

	if (me->query_skill_mapped("unarmed") != "taiji-quan")
		return notify_fail("你现在没有激发太极拳，不能使用「震」字诀。\n");

	if (me->query_skill_prepared("unarmed") != "taiji-quan")
		return notify_fail("你现在没有准备使用太极拳，无法使用「震」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = CYN "$N" CYN "默运神功，使出太极拳「震」字诀，企图以内力震伤$n"
	      CYN "。"NOR"\n";
	me->add("neili", -50);

	ap = me->query_skill("force");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(3);
		damage = ap + random(ap / 3);
		
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK,
					   damage, 50,
					   CYN "这一拳变化无方，气劲封了$n"
					   CYN "所有的退路，一拳正好命中！\n"
					   ":内伤@?");
	} else 
	{
		me->start_busy(3);
		msg += CYN "可是$p" CYN "看破了$P"
		       CYN "的企图，并没有上当。"NOR"\n";
	}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
