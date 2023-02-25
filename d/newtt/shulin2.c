//by admin 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","树林");

		set("exits", ([
		"west" : __DIR__"weiminggu",
	]));
	set("objects", ([
	//"/d/newtt/obj/hulu" :20,
//	"/d/newtt/obj/yeguo" :20,
	]));
		set("action_list", ([
	//	""HIM"新手指导"NOR :"newzhidao",
	//	""HIR"转世投胎"NOR :"zs",
	]));

	set("long","山谷中绿树成荫，却不见有多么明媚的花开于此，但你仍然能闻见远远飘来的花香。耳边听到了溪水叮咚的声音，原来不远处有一条蜿蜒的小溪，岸边似乎散落这一些物品。在山谷的北侧有条陡峭的山坡隐隐约约可以通往外界！");
	setup();
}

void init()
{
	add_action("zhuanshi","zs");
}

int zs(object me)
{
me=this_player();
me->move("/d/newtt/new1");
me->start_busy(1);
write("你来到了！\n");
return 1;
}

int valid_leave(object me, string dir)
{
//	if (dir == "west" &&  me->query("heshui")<1)
//	return notify_fail(HIY"请跟随新手指导的提示！\n"NOR);
me->set("shulin2",1);
	return ::valid_leave(me, dir);
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
