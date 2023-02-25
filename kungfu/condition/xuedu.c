// sanyin.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "xuedu"; }

string chinese_name() { return "血毒"; }

string update_msg_others()
{
       return "血毒发作，$N大叫一声突出一口血。\n";
}

string update_msg_self()
{
	return HIB "你只觉得一股股热流游走在身体内，疼痛难忍！"NOR"\n";
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
