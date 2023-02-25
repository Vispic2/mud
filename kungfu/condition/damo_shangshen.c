// huagu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit "/inherit/condition/damo";

string name() { return "damo_shangshen"; }

string chinese_name() { return "伤神之扰"; }

string update_msg_others()
{
       return HIC "$N" HIC "摇头晃脑，连眼睛都睁不开了，看上去困倦之极！"NOR"\n";
}

string update_msg_self()
{
	return HIR "只觉得自己精神不济，疲惫不堪，看来是受到达摩伤神剑的干扰。"NOR"\n";
}

string die_msg_others()
{
	return RED "$N" RED "深深的吸了几口气，就再也没有半点动静。"NOR"\n";
}

string die_reason()
{
	return "精神衰竭身亡了";
}

int jing_damage(object me, mapping cnd)
{
	int d;

	d = cnd["level"];

	if (d > 300 )
		d = 100 + (d - 300) / 12;
	else
	if (d > 60)
		d = 60 + (d - 60 ) / 6;
	d /= 3;
	if (d < 10) d = 10;

	return d / 2 + random(d);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
