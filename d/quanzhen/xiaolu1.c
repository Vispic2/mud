// xiaolu1.c 后山小路
inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这里是后山上的小路。这条小路好象不是人工刻意修出来的，
也许只是以前的采药人踩多了，现出这样一条小路来。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northeast" : __DIR__"xiaolu2",
		"southwest" : __DIR__"houshan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
