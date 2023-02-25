// break.c 五遁绝杀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "五遁"ZJBR"绝杀"; }

int perform(object me, object target)
{
	string msg;
	int count;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「五遁绝杀」只能在战斗中使用。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的气不够，无法施展「五遁绝杀」！\n");

	if (me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，难以施展「五遁绝杀」！\n");

	if ((int)me->query("neili") < (int)me->query("max_neili") / 2)
		return notify_fail("你的真气不够，无法施展「五遁绝杀」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "使出五行遁中的「五遁绝杀」，身法"
	      "陡然间变得变幻莫测！"NOR"\n";

	message_combatd(msg, me);
	count = (int)me->query_skill("five-avoid") / 30 + 2;
	if (count > 5 ) count = 5;

	while (count--)
	{
		if (! target || (environment(target) != environment(me)) ||
		    ! me->is_fighting(target) ||
		    me->query("qi") < 20 ||
		    me->query("neili") < 20)
		{
			message_combatd(WHT "$N" WHT "的身形倏地一"
					"转，收身停住了脚步。"NOR"\n", me);
			break;
		} else

		message_combatd(WHT "$N" WHT "的身影在$n"
				WHT "身旁时隐时现 ..."NOR"\n", me, target);
		if (! COMBAT_D->fight(me, target))
			message_combatd(WHT "但是$N" WHT "始终没有找到机会出手！"NOR"\n", me);
		me->receive_damage("qi", 10);
		me->add("neili", -10);
	}

	me->start_busy(1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
