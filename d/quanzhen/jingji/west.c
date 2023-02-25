#include <room.h>
inherit ROOM;
#include "jjroom.h"

void create()
{
	set("short", "竞技场西");
	set("long", "这里是门派竞技场的西部。");
	set("exits", ([
		"southeast" : __DIR__"south",
		"east" : __DIR__"center",
		"northeast" : __DIR__"north",
	]));
	set("objects",([
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
