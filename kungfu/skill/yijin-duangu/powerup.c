#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "易筋"ZJBR"锻骨"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用易筋锻骨内功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW "$N暗自凝神，提运九阴真气，全身渐渐升起一层白雾。"NOR"\n", me);

	me->add_temp("apply/attack", skill / 3);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill / 3 :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的功力运行完毕，将内力收回丹田。\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
