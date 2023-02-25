#include <room.h>
inherit ROOM;
#include "jjroom.h"

void create()
{
	set("short", "竞技场东");
	set("long", "这里是门派竞技场的东部。");
	set("exits", ([
		"southwest" : __DIR__"south",
		"west" : __DIR__"center",
		"northwest" : __DIR__"north",
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
