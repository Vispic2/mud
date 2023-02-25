// shield.c 九阳护体神功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "九阳"ZJBR"护体"; }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用少林九阳功来提升自己的防御力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR "$N" HIR "默念少林九阳功的口诀：他"
			    "强由他强，小鸡拂山冈。他横任他横，"
			    "小猪照大江……\n刹那间只见$N" 
			HIR "全身顿时浮现出一层刚猛的劲气，将$P"
			HIR "全全笼罩。"NOR"\n", me);

	me->add_temp("apply/armor", skill / 2);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill / 2 :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("shield"))
	{
		me->add_temp("apply/armor", -amount);
		me->delete_temp("shield");
		tell_object(me, "你的少林九阳功运行完毕，将内力收回丹田。\n");
	}
}

