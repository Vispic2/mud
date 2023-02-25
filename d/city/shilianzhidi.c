// Room: /city/wumiao2.c

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", HIR"试炼之地"NOR);
	set("long",HIR "这里是试炼之地。"NOR);

	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_sleep_room", 1);

	set("exits", ([
		"north" : "/d/fuben/shenshou/ruko",
		"down" : __DIR__"wumiao",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
