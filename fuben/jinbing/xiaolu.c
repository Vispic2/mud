//by 秦始皇 qsh ednpc tools.
// xiaolu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","关外小路");
	set("long","这里是关外小路，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"xiaolu2",
		"west" : __DIR__"enter",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/mitan":random(2),
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
