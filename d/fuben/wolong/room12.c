// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "西厢房");
	set("long", @LONG
这里是卧龙堡的一处厢房。
LONG
	);
	set("exits", ([
		"east" : __DIR__"room1",
	]));
	set("objects", ([
		__DIR__"npc/jiaotou": 4,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
