// tulu1.c
// Date: Nov.1997 by Venus

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
路旁一条小溪。溪水哗哗地流着，不时有鱼儿(fish)跃出水面。
溪旁几各男孩正低着头专心在钓鱼。
LONG);
	set("exits", ([
	    "southwest"     : __DIR__"shanlu5",
	    "northeast"     : __DIR__"maojiabu",
	]));

	set("objects", ([
	    __DIR__"npc/boy" : 2,
	]));

	set("item_desc", ([
		"fish" : "“哗”一条大鱼跃水而出，“噗”的一声"
			 "又掉回水里。渐得男孩一身水。\n",
	]));

	set("resource/fish", ({ "/clone/fish/liyu",
				"/clone/fish/jiyu",
				"/clone/fish/qingyu",
				"/clone/fish/caoyu", }));

	set("outdoors", "hangzhou");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
