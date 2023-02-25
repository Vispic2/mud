//by 秦始皇 qsh ednpc tools.
// xiaolu3.c

#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIG"草地"NOR);
	set("qilin",1);
	set("exits", ([
		"north" : __DIR__"xiaolu28",
		"south" : __DIR__"xiaolu26",
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
