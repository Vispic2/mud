#include <room.h>
inherit ROOM;
#include "jjroom.h"

void create()
{
	set("short", "竞技场北");
	set("long", "这里是门派竞技场的北部。");
	set("exits", ([
		"southeast" : __DIR__"east",
		"south" : __DIR__"center",
		"southwest" : __DIR__"west",
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
