// Room: /d/henshan/hsroad7.c 林间大道
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "林间大道");
	set("long", @LONG
这里是一条林间大道，在树丛中蜿蜒。这里是湖北境内。南边是
湖南。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"north"  : __DIR__"hsroad8",
		"south"  : __DIR__"hsroad6",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
