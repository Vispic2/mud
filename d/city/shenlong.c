// Room: /city/shenlong.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "神龙教");
	set("long", @LONG
shen long
需要更多的说明……
LONG );

	set("exits", ([
		"west" : __DIR__"road7",
	]));
	set("no_clean_up", 0);

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
