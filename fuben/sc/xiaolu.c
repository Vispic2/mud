//by 秦始皇 qsh ednpc tools.
// xiaolu.c

#include <ansi.h>
inherit ROOM;

void create()
{
		set("short",HIW"灵脉窟"NOR);
	set("qilin",1);
	
		set("exits", ([
		"north" : "/fuben/sc/sjsj",
		"east" : __DIR__"xiaolu2",
		"west" : __DIR__"qilin1",
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
