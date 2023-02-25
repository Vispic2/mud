// Room: by寒江雪
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIC"石室"NOR);
	set("long", @LONG
这里阴森森的！
LONG
	);
	set("exits", ([
		"south" : __DIR__"h12",
	]));
	set("objects", ([
		__DIR__"npc/l": 1,
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
