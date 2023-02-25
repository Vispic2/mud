// po.c 「总诀式」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "总决式"; }

int perform(object me)
{
	string msg;
	object weapon;
	int skill, jing_cost;
	int improve;

	skill = me->query_skill("lonely-sword", 1);
	jing_cost = random(20) + 45 - (int)me->query("int");
	if (jing_cost < 5) jing_cost = 5;

	if (environment(me)->query("no_fight"))
		return notify_fail("这里太嘈杂，你不能静下心来演练。\n");

	if (me->is_fighting())
		return notify_fail("「总诀式」不能在战斗中演练。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先去找一把剑。\n");

	if (! skill || skill < 20)
		return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");

	if (me->query("neili") < 50)
		return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");

	if (me->query("jing") < jing_cost)
		return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");

	if (! me->can_improve_skill("lonely-sword"))
		return notify_fail("你的实战经验不够，无法体会「总诀式」！\n");

	tell_object(me, HIG "你使出独孤九剑之「总诀式」，将手中" + weapon->name() + HIG "随意挥舞击刺。"NOR"\n");

	me->add("neili", -40 - random(10));
	me->receive_damage("jing", jing_cost);

	improve = 1 + random(me->query("int"));

	tell_object(me, MAG "你的「基本剑法」和「独孤九剑」进步了！"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", improve / 2);

	improve += me->query_skill("martial-cognize", 1) / 10;
	
	me->improve_skill("lonely-sword", improve*3);
	
	
	me->start_busy(random(3));
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
