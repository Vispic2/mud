// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里有四条走廊通向不同的房间。四周是拱猪小屋。
LONG );
	set("exits", ([
		"east"  : __DIR__ "eproom",
		"west"  : __DIR__ "wproom",
		"south" : __DIR__ "sproom",
		"north" : __DIR__ "nproom",
		"down"  : __DIR__"duchang",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
