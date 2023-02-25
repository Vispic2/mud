//by 秦始皇 qsh ednpc tools.
// xiaolu9.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR"麒麟洞"NOR);
	set("qilin",1);
	set("exits", ([
		"east" : __DIR__"xiaolu8",
			"north" : __DIR__"xiaolu10",
			"south" : __DIR__"xiaolu17",
			"west" : __DIR__"xiaolu23",
	]));
set("objects", ([
				"/d/aaa/npc/qilin" :1,
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
