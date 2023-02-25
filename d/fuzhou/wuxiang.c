// Room: /d/fuzhou/wuxiang.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "无相庵");
	set("long", @LONG
一个小小庵堂。
LONG );
	set("exits", ([
		"south" : __DIR__"shulin",
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
