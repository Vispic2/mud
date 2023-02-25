#include <room.h>
inherit ROOM;

void create()
{
	set("short", "永内东街");
	set("long", @LONG
永内东街是一条繁华的大街，也是北京最杂乱的地段。一条宽阔的青石大
道从中穿过，向东西两头延伸。西边是京城里著名的凡陛桥。
LONG );
	set("exits", ([
		"west" : __DIR__"yong_2",
	]));

	set("outdoors", "beijing");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
