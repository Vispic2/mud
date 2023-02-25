// Room: /city/tianshan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "天山");
	set("long", @LONG
tian shan
需要更多的说明……
LONG
	);

	set("exits", ([
		"east" : __DIR__"road2",
	]));

	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
