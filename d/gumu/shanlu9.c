// shanlu9.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱
郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭
峻，山川毓秀，不少鸟ㄦ在枝头高声啼唱不绝。往南下是两块耸天而
立的巨石。往北是一片蓊郁的山林。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"northup"    : __DIR__"shulin9",
		"southdown"  : __DIR__"riyueyan",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
