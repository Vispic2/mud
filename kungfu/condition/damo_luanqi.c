// huagu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit "/inherit/condition/damo";

string name() { return "damo_luanqi"; }

string chinese_name() { return "乱气之扰"; }

string update_msg_others()
{
       return HIC "$N" HIC "惨哼两声，整个人摇摇晃晃，站立不稳！"NOR"\n";
}

string update_msg_self()
{
	return HIR "忽然觉得一阵难受，心虚气短，看来是受到达摩乱气剑的干扰。"NOR"\n";
}

string die_msg_others()
{
	return RED "$N" RED "呻吟了半天，终于渐渐没有了声音。"NOR"\n";
}

string die_reason()
{
	return "气尽身亡了";
}

int qi_damage(object me, mapping cnd)
{
	int d;

	d = cnd["level"];

	if (d > 300 )
		d = 100 + (d - 300) / 12;
	else
	if (d > 60)
		d = 60 + (d - 60 ) / 6;
	if (d < 10) d = 10;

	return d / 2 + random(d);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
