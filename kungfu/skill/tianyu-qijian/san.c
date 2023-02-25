// san.c  天女散花

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "天女"ZJBR"散花"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天女散花」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("tianyu-qijian", 1) < 100)
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功实在太差，没法用「天女散花」。\n");

	if ((int)me->query("neili", 1) < 300)
		return notify_fail("你现在内力太弱，不能使用「天女散花」。\n");

	if (me->query_skill_mapped("sword") != "tianyu-qijian")
		return notify_fail("你没有激发天羽奇剑，没法用「天女散花」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n"
	      HIY "。"NOR"\n";

	message_combatd(msg, me, target);
	me->add("neili", -100);

	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->start_busy(1 + random(5));

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
