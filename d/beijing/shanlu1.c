
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是荒凉的山路，只有一条蜿蜒崎岖的小径。
LONG );
	set("exits", ([
		"northup" : __DIR__"shanlu2",
		"eastdown": __DIR__"zhuang1",
	]));
 	set("outdoors", "beijing");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
