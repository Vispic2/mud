// /d/xingxiu/silk1.c
// Jay 3/17/96

inherit ROOM;

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是一条中原和西域之间的商道。东边有一座雄伟的关隘，西面则通往西域。
LONG );

	set("exits", ([
		"east" : __DIR__"jiayuguan",
		"west" : __DIR__"silk2",
	]));

	set("outdoors", "xiyu");

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
