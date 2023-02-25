// powerup.c 易筋经加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "易筋"ZJBR"真气"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能提升自己的战斗力。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	message_combatd(HIR "$N" HIR "淡淡一笑，脸现慈和之意，衣裳无"
			"风自动，似乎有一股气流回旋。"NOR"\n", me);

	me->add_temp("apply/attack", skill / 3);
	me->add_temp("apply/defense", skill / 3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill / 3 :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/defense", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的易筋经神功运行完毕，将内力收回丹田。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
