// shanlu2.c 山路
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路弯弯曲曲地通向山上。北面的山上好象有一片柏树林，
树林中隐隐露出亭子的一角，南面就是上山的路。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northeast" : __DIR__"shanlu3",
		"southeast" : __DIR__"shanlu4",
		"westdown" : __DIR__"shanlu1",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
