// kuihua.c 「葵花心法」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "葵花"ZJBR"心法"; }
string *pfm_type() { return ({ "xinfa", }); }

int exert(object me, object target)
{
	string msg;
	object weapon;
	int skill, jing_cost;
	int improve;

	skill = me->query_skill("kuihua-mogong", 1);
	jing_cost = 45 - (int)me->query("int");
	if (jing_cost < 5) jing_cost = 5;

	if ( environment(me)->query("no_fight") )
		return notify_fail("这里太嘈杂，你不能静下心来运习。\n");

	if (me->is_fighting())
		return notify_fail("「葵花心法」不能在战斗中运习。\n");

	if (! skill || skill < 80)
		return notify_fail("你的葵花魔功等级不够, 不能运习「葵花心法」！\n");

	if (me->query("neili") < 30)
		return notify_fail("你的内力不够，无法运习「葵花心法」！\n");

	if (me->query("jing") < jing_cost)
		return notify_fail("你现在太累了，无法集中精神运习「葵花心法」！\n");

	if (! me->can_improve_skill("dodge"))
		return notify_fail("你的实战经验不够，无法体会「葵花心法」！\n");

	if (me->query("dodge", 1) >= me->query_skill("kuihua-mogong", 1) + 10)
		return notify_fail("你的葵花魔功修为有限，无法领会更高深的「葵花心法」！\n");

	msg = HIM "$N" HIM "盘膝默坐，暗自运习葵花心法，只觉得身子越来越轻。"NOR"\n";
	message_combatd(msg, me);

	me->add("neili", -20 - random(10));
	me->receive_damage("jing", jing_cost);

	improve = 20 + random(me->query("int"));

	tell_object(me, MAG "你的「基本轻功」进步了！"NOR"\n");
	me->improve_skill("dodge", improve);
	me->start_busy(random(3));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
