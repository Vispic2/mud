//by 秦始皇 qsh ednpc tools.
// xiaolu14.c

#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIC"蒙古包"NOR);
	set("qilin",1);
		set("exits", ([
		"east" : __DIR__"xiaolu14",
		"south" : __DIR__"xiaolu16",
	]));
set("objects", ([
			"/d/aaa/npc/menggubing" :1,
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
