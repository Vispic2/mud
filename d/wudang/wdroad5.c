//Room: wdroad5.c
//Date: Feb.12 1998 By Java

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。四周是浓密的树林，阴森森
的十分怕人。西北方就是陕鄂边界了。北边却是一片草地。抬头远望，隐
隐约约能够看到武当山的影子，只令人想飞奔而上。
LONG);
	set("outdoors", "wudang");
	set("exits", ([
	    "northwest" : __DIR__"wdroad6",
	    "north"     : "/d/xiangyang/caodi6",
	    "east"      : __DIR__"wdroad4",
	]));
	setup();
}

void init()
{
	add_action("do_float", "float");
	add_action("do_float", "piao");
}

int do_float()
{
	object me;

	me = this_player();

	if (me->query_skill("tiyunzong", 1) < 160 ||
	    me->query_skill("dodge", 1) < 160)
	{
		message_vision("$N跳了跳，原地蹦哒了一会儿。\n", me);
		return 1;
	}

	if (me->query("neili") < 150)
	{
		tell_object(me, "你的内力不够，还是休息一下再说吧。\n");
		return 1;
	}

	me->add("neili", -120);

	message_sort(HIC "$N" HIC"深吸一口气，迈开大步，双足"
		     "如飞，踩着山间杂草，飘然而起，直奔那武"
		     "当山去了！转瞬不见，只留下远远一个影子。"NOR"\n", me);
	tell_object(me, "片刻，你已经飞身上了武当山上。\n");
	me->move("/d/wudang/guangchang");
	message("vision", "只见一阵清风掠过，" + me->name() +
		"已经飘然而至。\n", environment(me), ({ me }));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
