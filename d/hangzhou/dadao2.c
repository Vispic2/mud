// dadao2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "沿湖大道");
	set("long", @LONG
一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵
人。本来风景秀丽之处，却显的一片萧瑟。大道向西南和北延伸。
LONG);
	set("exits", ([
	    "north"     : __DIR__"dadao1",
	    "southwest" : __DIR__"dalu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hangzhou");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
