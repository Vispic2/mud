// zhua_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "zhua_poison"; }

string chinese_name() { return "凝血之毒"; }

string update_msg_others()
{
       return HIR "$N忽然打了一个哆嗦,脸上露出痛苦而诡异的笑容。"NOR"\n";
}

string update_msg_self()
{
	return HIB "忽然一丝热流自体内升起, 缓缓的浸入你四肢百"
		   "骸。你中的凝血神抓毒性发作了！"NOR"\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
