#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIY "果汁冰" NOR, ({"fruit water","fruit"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",HIG "这是一杯由新鲜橘汁制成的果汁冰，冰得刚好，看起来诱人极了。"NOR"\n");
		set("unit", "杯");
		set("value", 100);
		set("max_liquid", 5);
	}

	set("liquid", ([
		"type": "water",
		 "name":HIY "果汁冰" NOR,
		"remaining": 5,
		"supply": 10,
		"drunk_apply": 3,
	]));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
