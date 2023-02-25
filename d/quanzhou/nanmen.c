// Room: /d/quanzhou/nanmen.c
inherit ROOM;

void create()
{
	set("short", "泉州南门");
	set("long", @LONG
这里是南方第一港泉州的南门。南门外是一片荒野。
LONG );
	set("exits", ([
		"north" : __DIR__"zhongxin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
