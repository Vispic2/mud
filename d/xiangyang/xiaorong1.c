// Room: /d/xiangyang/xiaorong1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
这里是襄阳城内老百姓的居住区。只见小弄两边是有些小
店面，有米行、小杂货铺等。一些居民从这里进进出出。
LONG );
	set("outdoors", "xiangyang");

	set("exits", ([
		"west" : __DIR__"jiekou2",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 2,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
