// shield.c 护体神功
//

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用神照经神功来提升自己的防御力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("shenzhao-jing", 1) < 50)
		return notify_fail("你的神照经神功修为不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW "$N" HIW "冷哼一声，默运玄功，运"
                        "用罡气护住了全身。\n" NOR, me);

	me->add_temp("apply/armor", skill );
	me->add_temp("apply/dodge", skill /6);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill  :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shield"))
        {
        	me->add_temp("apply/armor", -amount);
        	me->add_temp("apply/dodge", -amount/6);
        	me->delete_temp("shield");
        	tell_object(me, "你的神照经神功运行完毕，将内力收回丹田。\n");
        }
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/