// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "九头魔河");
	set("long", @LONG
这是九头妖蛇的领地九头魔河，四周弥漫着邪恶的气息，一股股恶臭传来。
LONG );
	set("objects", ([
	//	"/fuben/npc" : 1,
	]));
	set("outdoors", "city");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
