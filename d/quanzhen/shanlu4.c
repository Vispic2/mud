// shanlu4.c 山路
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是山路的尽头，南面好象有一片小树林，折而向东，就是终南
山的山脚了。
LONG
	);
	set("outdoors", "wugong");
	set("exits", ([
		"northwest" : __DIR__"shanlu2",
		"eastup" : __DIR__"shanjiao",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
