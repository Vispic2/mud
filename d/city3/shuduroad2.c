// Room: shuduroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "蜀都道");
	set("long", @LONG
这里是蜀都大道，它横贯整个锦官城。向东就可以到提督府了。
平头百姓少了，路上大多是有头有脸的爷们。几个官兵顶盔贯甲打量
着过往行人。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
	    "west"  : __DIR__"westroad2",
	    "east"  : __DIR__"guangchang",
	]));

	set("objects", ([
	    "/d/city/npc/bing" : 2,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
