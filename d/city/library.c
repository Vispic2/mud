// literate.c

inherit ROOM;

void create()
{
	set("short", "图书馆");
	set("long", @LONG
这是一间极为隐蔽的图书收藏室。
LONG );
	set("exits", ([
		"south" : __DIR__"lichunyuan",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
