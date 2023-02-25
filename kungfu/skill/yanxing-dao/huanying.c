// huanying.c  雁行刀法「无形幻影」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "无形"ZJBR"幻影"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int i;

	if (! target) target = offensive_target(me);
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("手中没刀怎么使「无形幻影」？\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「无形幻影」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("yanxing-dao", 1) < 60 )
		return notify_fail("你雁行刀法不够娴熟，使不出「无形幻影」。\n");

	if ((int)me->query_skill("force") < 120 )
		return notify_fail(RED"你内功火候不够，无法施展「无形幻影」。"NOR"\n");

	if ((int)me->query("neili") < 80)
		return notify_fail(HIC"你现在真气不够，没能将「无形幻影」使完！"NOR"\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "大喝一声，全场四处游动，$n"
	      HIC "只看到$N" HIC "化做数团身影，漫天刀"
	      HIC "光席卷而来！"NOR"\n";
	message_combatd(msg, me, target);

	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->add("neili", -80);
	me->start_busy(1 + random(4));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
