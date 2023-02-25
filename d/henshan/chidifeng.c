// Room: /d/henshan/chidifeng.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "赤帝峰");
	set("long", @LONG
相传祝融能 "以火施化" ，是黄帝的 "火正官" ，并主管南方的事
务，死后葬于此，故名赤帝峰。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"shanlu2",
	   "eastdown"   : __DIR__"shanlu11",
	   "northdown"  : __DIR__"shanlu3",
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
