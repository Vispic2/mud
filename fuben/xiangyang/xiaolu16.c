//by 秦始皇 qsh ednpc tools.
// xiaolu14.c

#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIR"蒙古营地"NOR);
	set("qilin",1);
		set("exits", ([
		//"east" : __DIR__"xiaolu14",
		"north" : __DIR__"xiaolu15",
	]));
set("objects", ([
				"/d/aaa/npc/menggushouling" :1,
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
