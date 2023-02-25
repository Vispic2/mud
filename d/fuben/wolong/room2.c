// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是卧龙堡的练武场，中央站立着几个威风凛凛的大汉。
LONG
	);
	set("exits", ([
		"north" : __DIR__"room3",
		"south" : __DIR__"room1",
		"east" : __DIR__"room13",
		"west" : __DIR__"room14",
	]));
	set("room_hide", 1);
	set("objects", ([
		__DIR__"npc/zjiaotou": 1,
		__DIR__"npc/huyuan": 4,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
