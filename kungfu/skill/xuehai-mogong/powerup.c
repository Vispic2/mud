// powerup.c 血海魔功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "血海"ZJBR"战气"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用血海魔功来提升自己的战斗力。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);
	message_combatd(HIR "$N" HIR "仰天一声长哮，提运血海魔功，全身骨骼爆响，真气荡漾，衣衫顿时膨胀，气势迫人。"NOR"\n", me);
	me->add_temp("apply/attack", skill / 3);
	me->add_temp("apply/parry", skill / 3);
	me->add_temp("apply/dodge", skill / 3);
	me->set_temp("powerup", 1);

	me->start_call_out((:call_other, __FILE__, "remove_effect", me,
			   skill / 3:), skill/2);
	if (me->is_fighting()) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/parry", -amount);
		me->add_temp("apply/dodge", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的血海魔功运行完毕，将内力收回丹田。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
