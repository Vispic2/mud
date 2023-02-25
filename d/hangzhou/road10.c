// road10.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "青石大道");
	set("long", @LONG
沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，
一片太平热闹景象。街的东边是一座酒楼。
LONG);
	set("exits", ([
	    "north"     : __DIR__"road9",
	    "south"     : __DIR__"road11",
	    "east"      : __DIR__"jiulou",
	    "west"      : __DIR__"marryroom",
	]));
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
