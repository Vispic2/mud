// self.c 小周天运转
// Created by Doing Lu 10/7/2K

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "小周天运转" NOR; }

int perform(object me, string skill)
{
	int heal;

	if (me->query("jing") < 80)
		return notify_fail("你的精气不够，现在还不能施展小周天运转。\n");

	
	if (me->query("qi") >= me->query("eff_qi"))
	return notify_fail("你的体力很好，没有必要使用小周天运转。\n");

	
if(me->query("tianfu/self") < 3){
    if (me->is_fighting())
	return notify_fail("你正在打架，无法使用小周天运转。\n");
}
    message_vision(HIC "$N" HIC "双手平举，深深吐出了一"  "口气，脸色变得圆润多了。"NOR"\n", me);
	tell_object(me, HIG "你感觉到你的气力恢复了。"NOR"\n");
	me->receive_damage("jing", 70 + random(30));
	heal = me->query_con() * 20+(me->query("tianfu/self")*100);
	me->receive_heal("qi", heal);
	me->start_busy(1 + random(5));
	
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
