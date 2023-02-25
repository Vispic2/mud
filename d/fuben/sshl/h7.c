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
		"north" : __DIR__"h8",
		"south" : __DIR__"h5",
	]));
	set("objects", ([
		__DIR__"npc/e": 2,
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
