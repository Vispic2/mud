#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"NAME迷宫"NOR);
	set("long", HIG"这个NAME巫师的迷宫\n"NOR);
	set("exits", ([
		"east" : __DIR__"name"+(random(100)+1),
		"south" : __DIR__"name"+(random(100)+1),
        "west" : __DIR__"name"+(random(100)+1),
        "north" : __DIR__"name"+(random(100)+1),
	]));        
	set("no_clean_up", 0);
	setup();	
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
