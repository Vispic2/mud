// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "邪气"ZJBR"冲天"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用辟邪剑法提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！\n");

	if (me->query_skill("pixie-jian", 1) < 120)
		return notify_fail("你的辟邪剑法修行不够，难以运功。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR "$N" HIR "身形忽然变得诡秘异常，进退"
			"之间飘忽不定，令人无从捉摸。"NOR"\n", me);

	me->add_temp("apply/attack", skill / 3);
	me->add_temp("apply/dodge", skill * 2 / 5);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int level)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -(level / 3));
		me->add_temp("apply/dodge", -(level * 2 / 5));
		me->delete_temp("powerup");
		tell_object(me, "你的辟邪剑法运行完毕，将内力收回丹田。\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
