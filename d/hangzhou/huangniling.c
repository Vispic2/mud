// huangniling.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "黄泥岭");
	set("long", @LONG
一条黄土路弯弯曲曲，四周非常的安静。偶而才看见些游人匆匆而过。
南北分别是下山的路。
LONG);
	set("exits", ([
	    "southdown"   : __DIR__"maojiabu",
	    "northdown"   : __DIR__"road3",
	]));
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
