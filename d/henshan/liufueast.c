// liufueast.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "刘府东厢房");
	set("long", @LONG
这儿是东厢房，这儿整理得干干净净，窗外露出点绿绿的枝叶，家
具上一尘不染，地上铺着很大块的青砖，一点灰尘也不沾。
LONG);
	set("exits", ([
	    "west"   : __DIR__"liufudating",
	]));
	set("objects", ([
		__DIR__"npc/liufuren" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
