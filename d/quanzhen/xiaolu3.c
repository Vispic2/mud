// xiaolu3.c 后山小路
inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这里是后山上的小路。这条小路好象不是人工刻意修出来的，
也许只是以前的采药人踩多了，现出这样一条小路来。走到这里，
你好象迷路了。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"east" : __DIR__"xiaolu4",
		"west" : __DIR__"xiaolu2",
		"north" : __DIR__"xiaolu5",
		"south" : __DIR__"xiaolu7",
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
