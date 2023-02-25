// kuang.c 狂风剑

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "狂风"ZJBR"剑法"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「狂风剑」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("「狂风剑」开始时必须拿着一把剑！\n");

	if (me->query_temp("powerup"))
		return notify_fail("你现在已经将内力充分运起了，无法再施展狂风剑法！\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你的真气不够，无法施展狂风剑法！\n");

	if ((int)me->query_skill("kuangfeng-jian", 1) < 100)
		return notify_fail("你的狂风剑法还不到家，无法施展「狂风剑」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "大喝一声，手中的" + weapon->name() +
	      HIC "犹如狂风疾电一般劈刺向$n" HIC "！\n"
	      HIC "霎时间只见剑气层层叠叠如波浪般汹涌而起，$n"
	      HIC "只觉得呼吸登时不畅。"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -150);

	count = me->query_skill("sword") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
