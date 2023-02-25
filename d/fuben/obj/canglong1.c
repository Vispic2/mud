//canglong1.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "高级藏宝图" NOR, ({ "senior cangbao tu" }));
	set("long", "一张卧龙堡藏宝图。\n");
	set("unit", "张");
	set("value", 10);
	set("fuben_type", "canglong");
	set("only_do_effect", 1);
	set("weight", 10);
	
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	message_vision(CYN "$N" CYN "拿着一张" + name() + CYN "，开始对比着观察四周。"NOR"\n", me);
	
	if (!query("where")) {
		tell_object(me,"你拿着藏宝图左看右看，发现这张藏宝图原来是假的。\n");
		return 1;
	}
	if(base_name(environment(me))!=query("where"))
	{
		tell_object(me,"你对照藏宝图在这里仔细搜索了一阵，结果却毫无收获。\n");
		return 1;
	}

	if(FUBEN_D->create_fuben(me, query("fuben_type")))
	{
		message_vision(CYN "$N" CYN "发现了一个神秘的入口，不知通向哪里？"NOR"\n", me);
		destruct(this_object());
	}

	return 1;
}
#include "roombao.h"
void init()
{	
	do_copy();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
