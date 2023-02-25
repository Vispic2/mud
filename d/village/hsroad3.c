// hsroad3.c
inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
一条坑坑洼洼的土路，弯弯曲曲的通向山里。
LONG );
	set("outdoors", "village");
	set("exits", ([
		"southeast" : __DIR__"hsroad2",
		"north"     : __DIR__"sexit",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 4,
	]));

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
