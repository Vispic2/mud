#include <room.h>
inherit ROOM;
#include "jjroom.h"

void create()
{
	set("short", "竞技场南");
	set("long", "这里是门派竞技场的南部。");
	set("exits", ([
		"northeast" : __DIR__"east",
		"north" : __DIR__"center",
		"northwest" : __DIR__"west",
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
