// z-dan.c
// 星星(lywin)炼丹任务附属道具
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("九转能蛇丸", ({"gdan2", "dan2"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗九转能蛇丸。\n");
		set("value", 15000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query("max_neili") < 600 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗九转能蛇丸，只觉得头重脚轻，摇摇欲倒，原来功力不够，药效适得其反！\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N吃下一颗九转能蛇丸，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
        me->add_temp("apply/damage", 100);
        me->add("max_neili", 1);
        message_vision(HIG "$N吃下一颗九转能蛇丸，只觉得体内真力源源滋生，你的杀伤力提高了!\n" NOR, me);
	}

        me->apply_condition("medicine", 120);

	destruct(this_object());
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
