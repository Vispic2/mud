// lian.c 连环剑术

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "连环"ZJBR"剑术"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("连环剑术只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("没有剑怎么能施展连环剑术？\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展连环剑术！\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，难以施展连环剑术！\n");

	if ((int)me->query_skill("yunv-jian", 1) < 70)
		return notify_fail("你的玉女剑法还不到家，无法使用连环剑术！\n");

	if (me->query_skill_mapped("sword") != "yunv-jian")
		return notify_fail("你没有激发玉女剑法，无法使用连环剑术！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "身子轻轻一转，霎时向$n" HIC "劈出了数剑！"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -80);

	for (i = 0; i < 4; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->start_busy(1 + random(4));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
