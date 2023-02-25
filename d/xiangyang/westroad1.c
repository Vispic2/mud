// Room: /d/xiangyang/westroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "西内大街");
	set("long", @LONG
这是一条青石铺就的大街。隐隐地能望见南面是一座很高
的彩楼，东面是一堵盖着红色琉璃瓦的高墙，里面是郭府大院。
西面是襄阳城老字号的客店，北面是青石铺的大街。
LONG );
	set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"kedian",
		"south" : __DIR__"westjie2",
		"north" : __DIR__"westroad2",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
