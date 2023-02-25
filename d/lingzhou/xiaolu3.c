// Room: /lingzhou/xiaolu3.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "林中小路");
	set("long", @LONG
这是陡坡上的一条杂草丛生的羊肠小路，看起来平时没什么人迹，
路边开着不知名的野花，两边的松树依然高大、挺拔。阳光透下来照
的你身上是斑斑驳驳的影子。
LONG );
	set("exits", ([
		"west"   : __DIR__"biangate",
		"east"   : __DIR__"xiaolu2",
	]));
	set("objects", ([
		"/d/emei/npc/camel" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
