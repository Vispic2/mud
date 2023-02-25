// xue.c 冰雪纷飞

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "冰雪"ZJBR"纷飞"; }

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
		return notify_fail("「冰雪纷飞」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("「冰雪纷飞」必须持杖在手！\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 80)
		return notify_fail("你的内功火候不够！\n");

	if ((int)me->query_skill("tianshan-zhang", 1) < 90)
		return notify_fail("你的天山杖法还不到家，无法使用冰雪纷飞！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "使出星宿绝技「冰雪纷飞」，招式变得诡秘异常！"NOR"\n";
	message_combatd(msg, me);
	me->add("neili", -100);

	for (i = 0; i < 5; i++)
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
