//by 秦始皇 qsh ednpc tools.
// xiaolu2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"灵脉窟"NOR);
	set("qilin",1);
	set("exits", ([
		"south" : "/fuben/sc/jsjsq",
	//	"east" : __DIR__"xiaojiuguan",
		"north" : __DIR__"xiaolu3",
		"west" : __DIR__"xiaolu",
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
