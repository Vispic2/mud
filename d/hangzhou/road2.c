// road2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
边是灵隐寺和飞来峰。往南是上天竺。
LONG);
	set("exits", ([
		"southup"   : __DIR__"shanlu1",
		"southwest" : __DIR__"road1",
		"northeast" : __DIR__"road3",
	]));
	set("objects", ([
	   __DIR__"npc/xianghuo" : 1,
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
