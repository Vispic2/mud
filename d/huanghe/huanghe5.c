// Room: /huanghe/huanghe5.c
// Java. Sep 21 1998

#include <room.h>

inherit BUILD_ROOM;
void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河岸边。黄河流淌到这里，河床宽阔。黄色的河水在静静
地向东流去，使人忘记它发洪水时的狂威。
LONG );
	set("exits", ([
		"east"      : "/d/taishan/daizong",
		"northeast" : __DIR__"huanghe6",
		"southwest" : __DIR__"huanghe4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("max_room", 5);
	setup();
	replace_program(BUILD_ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
