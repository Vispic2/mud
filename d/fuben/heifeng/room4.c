// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是黑风寨密室，外人很难发现。
LONG
	);
	set("exits", ([
		"up" : __DIR__"room3",
	]));
	set("room_hide", 1);
	set("objects", ([
		"/d/fuben/npc/tufei": 2,
		"/d/fuben/npc/hanfei": 1,
		"/d/fuben/obj/baoxiang1": 1,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
