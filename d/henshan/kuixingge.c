// Room: /d/henshan/kuixingge.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "奎星阁");
	set("long", @LONG
奎星阁是南岳大庙的第二进。阁为一个大舞台，阁左为鼓亭，右是
钟亭。乡俗年节唱戏，这里总是热闹非凡。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "south"  : __DIR__"lingxingmen",
	   "east"   : __DIR__"zhongting",
	   "north"  : __DIR__"zhengchuan",
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
