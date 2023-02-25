#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIR"仙宗◎火"NOR);
	set("long",HIR"                             仙宗◎火"NOR);
	set("exits", ([
	/*
		"east"  : __DIR__"dong1",
		"south" : __DIR__"nan1",
		"west"  : __DIR__"xi1",
		"north" : __DIR__"bei1",
		*/
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
