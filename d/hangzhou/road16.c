// road16.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
湖。北边可上雷峰，南边是净慈寺。
LONG);
	set("exits", ([
	    "northup" : __DIR__"xizhaoshan",
	    "south"   : __DIR__"jingcisi",
	    "east"    : __DIR__"road15",
	    "west"    : __DIR__"road20",
	]));
	set("objects", ([
	    __DIR__"npc/baizhen" : 1,
	]));
	set("outdoors", "hangzhou");
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
