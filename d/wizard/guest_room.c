// /d/wizard/guest_room.c

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这是巫师会客的地方。
LONG );

	set("objects", ([
		"/adm/npc/wizard" : 1,
		"/clone/misc/msgd" : 1,
	]));
	set("exits", ([
		"southeast" : "/d/city/wumiao",
		//"west" : "/data/home/l/lonely/wizard/wizard",
	]));

	set("no_fight", 1);

	create_door("southeast", "竹门", "northwest", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "up" && ! wizardp(me))
		return notify_fail("那里只有巫师才能进去。\n");
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
