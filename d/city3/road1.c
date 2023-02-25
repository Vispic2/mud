
//Room: road1.c
inherit ROOM;
void create()
{
	set("short","青石大道");
	set("long",@LONG
这是一条通往成都的大青石道，两旁绿树荫蔽，空气十分清新。
成都平原向称天府之国，这里四周田野稻浪滚滚，平平展展的大地
上，偶尔会出现一大丛翠竹浓荫，细细认去，都是人家居处。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
	    "east"       : "/d/emei/qsjie1",
	    "northwest"  : __DIR__"road2",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
