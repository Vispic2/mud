// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "怒涛"ZJBR"潮涌"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用怒涛潮涌提升自己的战斗力。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -200);
	me->receive_damage("qi", 0);

	message_combatd(HIC "$N" HIC"一声长啸，激起一阵狂风，气"
			"浪翻翻滚滚，向两旁散开。\n霎时之间，便"
			"似长风动起，气云聚合，天地渺然，有如海"
			"浪滔滔。"NOR"\n", me);

	me->add_temp("apply/attack", skill * 2 / 5);
	me->add_temp("apply/defense", skill * 2 / 5);
	me->add_temp("apply/damage", skill / 4);
	me->add_temp("apply/unarmed_damage", skill / 4);
	me->set_temp("powerup", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);
	if (me->is_fighting()) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int skill)
{
	if (me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -(skill * 2 / 5));
		me->add_temp("apply/defense", -(skill * 2 / 5));
		me->add_temp("apply/damage", -(skill / 4));
		me->add_temp("apply/unarmed_damage", -(skill / 4));
		me->delete_temp("powerup");
		tell_object(me, "你的怒涛潮涌运行完毕，将内力收回丹田。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
