// shield.c 护体神功
//

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "邪气"ZJBR"护体"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用辟邪剑法来提升自己的防御力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("pixie-jian", 1) < 50)
		return notify_fail("你的辟邪剑法修为不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW "$N" HIW "身子忽前忽后，忽左忽右，一"
			"层层气浪跌宕翻涌，护住全身！"NOR"\n", me);

	me->add_temp("apply/armor", skill *2 / 2);
	me->add_temp("apply/armor1", skill *1 / 2);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill * 2 / 2 :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (!me) return;

	me->add_temp("apply/armor", -amount);
	me->add_temp("apply/armor1", -amount/2);
	me->delete_temp("shield");
	tell_object(me, "你的辟邪剑法运行完毕，将内力收回丹田。\n");
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
