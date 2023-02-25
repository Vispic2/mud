// Room: /d/quanzhou/riyuetan.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "日月潭");
	set("long", @LONG
翠峰环抱，湖水澄碧的日月潭，潭北形如日轮，潭南
弯曲如月，为台湾避暑胜地。
LONG );
	set("exits", ([
		"westdown" : __DIR__"chiqian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
