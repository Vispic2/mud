//by admin(寒江雪) 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"灵脉窟"NOR);
	set("long","这里是灵脉窟。");
	set("exits", ([
		"east" : "/fuben/sc/jzjz",
		"north" : "/fuben/sc/zjzj",
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
