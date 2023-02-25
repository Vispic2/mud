// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "西厢房");
	set("long", @LONG
这里是山寨里的一处西厢房。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room14",
	]));
	set("objects", ([
		"/d/fuben/npc/tufei": 1,
		"/d/fuben/obj/baoxiang": 1,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
