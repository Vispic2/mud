// room: liang.c
//Jay 4/7/96

#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","密室房梁");
       set("long", @LONG
你现在在密室的房梁上四下观瞧，周围都是些烂木头破砖瓦。
LONG );
	set("exits", ([
		"down" : __DIR__"mishi",
	]));       
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
