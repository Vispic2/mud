//heifeng1.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "藏宝图" NOR, ({ "cangbao tu" }));
	set("long", "一张黑风寨藏宝图。\n");
	set("unit", "张");
	set("value", 10);
	set("fuben_type", "heifeng");
	set("only_do_effect", 1);
	set("weight", 10);

	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	//if (!wizardp(me))
	//	return notify_fail("暂时关闭藏宝图副本，等修复后将重新开放。\n");
	
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
            //me->command("fuben");
            tell_object(me,ZJFORCECMD("fuben"));
		destruct(this_object());
	}

	return 1;
}
#include "roombao.h"
void init()
{	
	do_copy();
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
