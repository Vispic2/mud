// Object: /d/xiangyang/obj/tihu-xiang.c 醍醐香  
// 白花，花香醉人，闻得稍久，便和饮了烈酒一般，借鉴自侠客行佛山醍醐香程序。

#include <ansi.h>

inherit ITEM;

void create() 
{
	set_name(HIW "醍醐香" NOR, ({ "tihu xiang", "xiang"}) );
	set("weight", 10);
	if (clonep())
	    set_default_object(__FILE__);
	else 
	{
	    set("long", "一朵小白花，花香浓郁。\n");
	    set("unit", "朵");
	    set("material", "wood");
	}
	setup();
}

void init()
{
	add_action("do_smell", "smell");
}

int do_smell(string arg)
{
	object me;
	me = this_player();

	if (! id(arg))
	    return notify_fail("你要闻什么？\n");

	me->apply_condition("drunk", (int)me->query_condition("drunk") + random(20));
	message_vision(HIG "$N" HIG "闻了闻醍醐香，一股浓郁的香气直冲头顶。"NOR"\n", me);
	return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
