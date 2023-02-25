// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "葵花"ZJBR"无敌"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用葵花无敌提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！\n");

	if (me->query_skill("kuihua-xinfa", 1) < 120)
		return notify_fail("你的葵花心法修行不够，难以运功。\n");

	if ((int)me->query_temp("kuihuawudi"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR "$N" HIR "心里默念葵花无敌，四周战气逼人，令人发指！"HIY"你感觉你的后天臂力、悟性、根骨、身法得到了提升！"NOR"\n", me);

	me->add_temp("apply/int", skill / 20);
	me->add_temp("apply/dex", skill / 20);
	me->add_temp("apply/str", skill / 20);
	me->add_temp("apply/con", skill / 20);
	me->set_temp("kuihuawudi", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int level)
{
	if ((int)me->query_temp("kuihuawudi"))
	{
		
	me->add_temp("apply/int", -(level / 20));
	me->add_temp("apply/dex", -(level / 20));
	me->add_temp("apply/str", -(level / 20));
	me->add_temp("apply/con", -(level / 20));
		
		
		me->delete_temp("kuihuawudi");
		tell_object(me, HIR"你的葵花无敌运行完毕。\n"NOR);
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
