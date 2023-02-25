// Room: /city/xidajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，行人
稀少，静悄悄地很是冷清。东边是一个热闹的广场。南边是兵营。北边就是衙
门了。
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"guangchang",
		"south" : __DIR__"bingyindamen",
		"west"  : __DIR__"xidajie2",
		"north" : __DIR__"yamen",
	]));

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
