// road3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道两边遍植青松，满目苍翠，偃盖如雪。被称为“九里雪松”。
东北边是洪春桥。再向西南便到了灵隐寺。南边是一条土路。
LONG);
	set("exits", ([
	    "southup"     : __DIR__"huangniling",
	    "southwest"   : __DIR__"road2",
	    "northeast"   : __DIR__"hongchunqiao",
	]));
	set("outdoors", "hangzhou");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
