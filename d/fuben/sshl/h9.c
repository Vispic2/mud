// Room: by寒江雪
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
这里阴森森的！
LONG
	);
	set("exits", ([
		"south" : __DIR__"h10",
		"west" : __DIR__"h8",
		"east" : __DIR__"h15",
	]));
	set("objects", ([
		__DIR__"npc/e": 1,
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
