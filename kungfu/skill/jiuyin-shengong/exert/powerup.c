// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "九阴"ZJBR"战气"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
int jysg,jysgs;
jysg=me->query("jysg");
	if (target != me)
		return notify_fail("你只能用九阴神功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够!");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	if(me->query_skill_mapped("force")!="jiuyin-shengong")
		return notify_fail("需要激发九阴神功为当前内功。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIY "$N" HIY "缓缓的吐出了一口气，只"
			"见衣袖飘飘、气涨如鼓，似要飞扬！"NOR"\n", me);

	me->add_temp("apply/attack", skill * 2 / 4);
	me->add_temp("apply/defense", skill * 2 / 4);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill * 2 / 4 :), skill);

	if (me->is_fighting())
	 me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/defense", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的九阴神功运行完毕，将内力收回丹田。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
