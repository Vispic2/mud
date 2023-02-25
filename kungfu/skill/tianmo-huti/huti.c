#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return ""HIC"天魔"ZJBR""HIC"护体"NOR""; }

int perform(object me, object target)
{
	int skill;

	if ((int)me->query("neili") < 1000)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("tianmo-huti", 1) < 180)
		return notify_fail("你的天魔护体神功修为不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经运起护体神功了。\n");

	skill = me->query_skill("force");
	me->add("neili", -500);
	me->receive_damage("qi", 0);

	message_combatd(HIY "只听$N" HIY "高呼佛号，霎那间皮肤竟犹如镀金一般，发出灿灿金光。"NOR"\n", me);

	me->add_temp("apply/armor", skill / 2);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) 
	me->start_busy(1);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("shield"))
	{
		me->add_temp("apply/armor", -(amount / 2));
		me->delete_temp("shield");
		tell_object(me, "你的天魔护体神功运行完毕，将内力收回丹田。\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
