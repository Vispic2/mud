#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "ningxue_shenzhao"; }

string chinese_name() { return "凝血之扰"; }

string update_msg_others()
{
       return HIR "$N" HIR "只感内息顿滞，“哇”的一声喷出一大口鲜血。"NOR"\n";
}

string update_msg_self()
{
	return HIR "你只感内息顿滞，全身血液竟渐渐的开始凝固起来！"NOR"\n";
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
