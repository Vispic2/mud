// road18.c
// Date: Nov.1997 by Venus

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
湖。大道伸向东北和南两边，往西是石屋洞，往东是一条山路。
LONG);
	set("exits", ([
	    "northeast" : __DIR__"road19",
	    "west"      : __DIR__"shiwudong",
	    "south"     : __DIR__"road17",
	    "east"      : __DIR__"yuhuangshan",
	]));
	set("outdoors", "hangzhou");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
