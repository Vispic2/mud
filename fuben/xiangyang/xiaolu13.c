//by 秦始皇 qsh ednpc tools.
// xiaolu13.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"蒙古包"NOR);
	set("qilin",1);
	set("exits", ([
		"south" : __DIR__"xiaolu14",
		"north" : __DIR__"xiaolu12",
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
