#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "升天"ZJBR"一剑"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;

	if (! target) target = offensive_target(me);

	if (userp(me) && ! me->query("can_perform/liuyue-jian/sheng"))
		return notify_fail("你现在还不会使用「天升」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天升」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("liuyue-jian", 1) < 150)
		return notify_fail("你的玉影流月剑法不够娴熟，不会使用「天升」。\n");

	if ((int)me->query_skill("force") < 140)
		return notify_fail("你的内功实在太差，没法用「天升」。\n");

	if ((int)me->query("neili", 1) < 300)
		return notify_fail("你现在内力太弱，不能使用「天升」。\n");

	if (me->query_skill_mapped("sword") != "liuyue-jian")
		return notify_fail("你没有激发玉影流月剑法，没法用「天升」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "手腕一阵疾抖，剑身微颤，剑作龙吟。刹那间剑芒陡涨，"
	      "如天河倒泻一般洒向$n"
	      HIW "。"NOR"\n";

	message_combatd(msg, me, target);
	me->add("neili", -100);

	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->start_busy(1 + random(6));

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
