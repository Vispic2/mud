// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "英雄厅");
	set("long", @LONG
这里是一处大厅，厅中央牌匾上写着几个金光闪闪的大字“英雄厅”。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room1",
		"north" : __DIR__"room3",
	]));
	set("objects", ([
		"/d/fuben/npc/hanfei": 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("han fei", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "north") {
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
