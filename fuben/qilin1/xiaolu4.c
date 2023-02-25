//by 秦始皇 qsh ednpc tools.
// xiaolu4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR"麒麟洞"NOR);
	set("qilin",1);
	set("exits", ([
		"east" : __DIR__"xiaolu3",
			"west" : __DIR__"xiaolu5",
	]));
set("objects", ([
				"/d/aaa/npc/qilin" :2,
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
