#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "隔山"ZJBR"打牛"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("隔山打牛只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用隔山打牛！\n");	 
		
	if ((int)me->query_skill("zhenshan-zhang", 1) < 60)
		return notify_fail("你的震山掌不够娴熟，不会使用隔山打牛。\n");

	if (me->query("max_neili") < 500)
		return notify_fail("你的内功修为不足，无法施展隔山打牛。\n");

	if (me->query("neili") < 150)
		return notify_fail("你现在真气太弱，无法施展隔山打牛。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = WHT "$N" WHT "脚蹲马步，深吸一口气，使出隔山打牛，双掌对准$n"
	      WHT "平平推出。"NOR"\n";
	me->add("neili", -100);

	ap = me->query_skill("force");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		me->start_busy(3);
		
		damage = ap / 2 + random(ap / 2);
		
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK,
					   damage, 35,
					   HIR "$n" HIR "见势连忙向后一纵，结果只感"
					   "胸口一震，顿时两耳轰鸣，原被$N" HIR 
					   "的内劲所伤！\n"
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
