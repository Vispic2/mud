// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
这里是山寨大院。
LONG
	);
	set("exits", ([
		"south" : __DIR__"enter",
		"north" : __DIR__"room2",
		"east" : __DIR__"room11",
		"west" : __DIR__"room14",
	]));
	set("objects", ([
		"/d/fuben/npc/tufei": 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("tu fei", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "north" || dir == "west" || dir == "east")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"对你大吼道：站住！\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
#include "/d/fuben/room_fb.h"
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
