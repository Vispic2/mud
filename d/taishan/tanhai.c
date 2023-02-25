// Room: /d/taishan/.c
inherit ROOM;

void create()
{
	set("short", "探海石");
	set("long", @LONG
这是一块从山崖向横突出的巨石，长约二丈余，向东直指渤海。
巨石三面无所凭依，视野广阔，但除非有绝高胆色的人，普通人一般
都不敢攀登这块探海石。
LONG );
	set("exits", ([
		"westdown" : __DIR__"riguan",
		"east" : __DIR__"dongtian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
