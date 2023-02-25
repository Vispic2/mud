//by admin(寒江雪) 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"灵脉窟"NOR);
	set("long","这里是灵脉窟。");
	set("exits", ([
		"north" : "/fuben/sc/nsn",
		"west" : "/fuben/sc/jsn",
		"south" : "/fuben/sc/baic",
		"east" : "/fuben/sc/sjsj",
	]));
	set("objects", ([
    "/d/aaa/npc/ling":1+random(3),	
]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
