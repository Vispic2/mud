//by 秦始皇 qsh ednpc tools.
// xiaolu6.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"蒙古包"NOR);
	set("qilin",1);
	set("exits", ([
		"west" : __DIR__"xiaolu7",
		"north" : __DIR__"xiaolu5",
	]));
set("objects", ([
			"/d/aaa/npc/menggubing" :2,
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
