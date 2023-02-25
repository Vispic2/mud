// powerup.c 九阳神功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "九阳"ZJBR"战气"; }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用九阳神功来提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR "$N" HIR "微一凝神，运起九阳心法，将真气"
			"凝聚在丹田之中，沿奇经八脉遍布全身！"NOR"\n", me);

	me->add_temp("apply/attack", skill * 2 / 5);
	me->add_temp("apply/parry", skill / 3);
	me->add_temp("apply/dodge", skill / 3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", - (amount * 2 / 5));
		me->add_temp("apply/parry", - (amount / 3));
		me->add_temp("apply/dodge", - (amount / 3));
		me->delete_temp("powerup");
		tell_object(me, "你的九阳心法运行完毕，将内力收回丹田。\n");
	}
}

