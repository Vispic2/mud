// caolianfang.c 操练房
// Modified by Marz 03/27/96

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "操练房");
	set("long", @LONG
这是二楼操练房上，四面八方都是打斗声，武当弟子来去匆匆。
LONG );
	set("exits", ([
		"south"     : __DIR__"caolian1",
		"north"     : __DIR__"caolian2",
		"west"      : __DIR__"caolian3",
		"eastdown"  : __DIR__"xilang"
	]));
	set("objects", ([
		CLASS_D("wudang") + "/yin" : 1
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
