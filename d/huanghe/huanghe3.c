// Room: /huanghe/huanghe3.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水
在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。
LONG );
	set("exits", ([
		"east"  : __DIR__"huanghe4",
		"west"  : __DIR__"huanghe2",
	]));
	set("objects", ([
		__DIR__"npc/bangzong" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
