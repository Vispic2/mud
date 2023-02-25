//by 秦始皇 qsh ednpc tools.
// xiaolu8.c

#include <ansi.h>
inherit ROOM;

void create()
{
		set("short",HIW"灵脉窟"NOR);
	set("qilin",1);
		set("exits", ([
		"west" : __DIR__"xiaolu9",
		"east" : __DIR__"xiaolu5",
	]));
set("objects", ([
			"/d/aaa/npc/ling" :1+random(3),
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
