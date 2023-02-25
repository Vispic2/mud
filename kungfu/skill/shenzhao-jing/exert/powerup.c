// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用神照经神功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够!");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIC "$N" HIC "大喝一声，一股气浪登时如波"
                        "涛一般散布开来，直吹得四周飞沙走石！\n" NOR, me);

	me->add_temp("apply/attack", skill  / 6);
	me->add_temp("apply/defense", skill  / 6);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
                           me, skill  / 6 :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
	        me->add_temp("apply/attack", -amount);
	        me->add_temp("apply/defense", -amount);
	        me->delete_temp("powerup");
                tell_object(me, "你的神照经神功运行完毕，将内力收回丹田。\n");
        }
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
