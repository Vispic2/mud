//by 秦始皇 qsh ednpc tools.
// xiaolu14.c

#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIR"麒麟洞"NOR);
	set("qilin",1);
		set("exits", ([
		"north" : __DIR__"xiaolu18",
		"west" : __DIR__"xiaolu20",
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
