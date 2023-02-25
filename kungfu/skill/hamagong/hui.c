// hui.c 蛤蟆功回息

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount);

string query_name() { return "蛤蟆"ZJBR"回息"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
	string msg;

	if (! (skill = me->query_temp("hmg_dzjm")))
		return notify_fail("你并没有倒转经脉啊。\n");

	msg = HIB "$N" HIB "缓缓吐出一口气，脸色变了变，阴阳不定。"NOR"\n";
	message_combatd(msg, me);

	me->add_temp("apply/dodge", -skill / 4);
	me->add_temp("apply/parry", -skill / 4);
	me->add_temp("apply/armor", -skill / 2);
	me->add_temp("apply/dispel_poison", -skill / 2);
	me->delete_temp("hmg_dzjm");

	me->set("neili", 0);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
