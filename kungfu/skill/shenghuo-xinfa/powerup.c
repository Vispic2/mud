#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "圣火"ZJBR"战意"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用圣火心法来提升自己的战斗力。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -150);
	message_combatd(HIM "$N默运圣火心法，脸色先由黄翻紫，紧接着由紫翻蓝，再由蓝翻红，最后又恢复为黄色，甚为诡异。"NOR"\n",me);
	me->add_temp("apply/attack", skill * 2 / 5);
	me->add_temp("apply/dodge", skill * 2 / 5);
	me->add_temp("apply/parry", skill * 2 / 5);
	me->set_temp("powerup", 1);

	me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill * 2 / 5 :), skill);
	if (me->is_fighting()) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/dodge", -amount);
		me->add_temp("apply/parry", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的圣火心法运行完毕，长长地吐了口气，将内力收回丹田。\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
