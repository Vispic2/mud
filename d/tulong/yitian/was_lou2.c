#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "万安寺第二层");
	set("long", @LONG
这里是万安寺的第二层，寺楼里站着几个身着火红袈裟的和尚。一见你上楼，
立马向你扑来。
LONG);
	set("exits", ([
	    "down"  : __DIR__"was_houdian",
	    "up"    : __DIR__"was_lou3",
	]));

	set("objects", ([
	    __DIR__"npc/18jingang-4zhang" :2,
	]));

	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "up" && objectp(present("zhang seng", environment(me))))
	   return notify_fail(CYN "杖僧齐声喝道：哪里走？滚下来！"NOR"\n");

	if (dir == "down" && objectp(present("zhang seng", environment(me))))
	   return notify_fail(CYN "杖僧齐声喝道：哪里逃？纳命来！"NOR"\n");

	return ::valid_leave(me, dir);
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
