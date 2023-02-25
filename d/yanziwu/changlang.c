//ROOM: /d/yanziwu/changlang.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long",@LONG
只见红栏碧瓦，一派富贵气象，不时有几只燕子灵巧的从廊见飞过，
长廊的尽头有一座大花园。长廊上似乎还有一层，你忍不住想爬上去看
看。
LONG );
	set("exits", ([
	    "east"  : __DIR__"huizhen",
	    "west"  : __DIR__"lixiang",
	    "north" : __DIR__"shijian",
	    "south" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
