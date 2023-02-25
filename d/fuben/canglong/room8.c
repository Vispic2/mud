// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "卧龙堡");
	set("long", @LONG
这是一处古城堡，四处冷冷清清，空气中充满血腥的味道，你越走越害怕……。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room"+(random(10)+1),
		"north" : __DIR__"room"+(random(10)+1),
		"up" : __DIR__"room"+(random(10)+1),
		"down" : __DIR__"room"+(random(10)+1),
		"west" : __DIR__"room"+(random(10)+1),
		"east" : __DIR__"room"+(random(10)+1),
	]));

	setup();
}
#include "/d/fuben/room_fb.h"
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
