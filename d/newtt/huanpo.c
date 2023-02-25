#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "缓坡");
	set("long", @LONG
这是华山后山的陡峭山崖，做上方便是华山派掌门岳不群的居室，居室
的窗户正对着你的头顶。
LONG );
	set("exits",([
		"north":__DIR__"jizhen",
	]));
	set("action_list",([
		"山坡":"zs",
	]));
	
	setup();
}


void init()
{
	add_action("zhuanshi","zs");
	//add_action("do_look","enter");
}

int zhuanshi(object me)
{
me=this_player();

me->move("/d/newtt/weiminggu");
me->start_busy(1);
write("你从山坡上一跃而下，竟然毫发无损！\n");
return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
