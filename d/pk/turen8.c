// Room: /d/pk/turen8.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR "殒命场" NOR);
	set("long", @LONG
这里阴森恐怖，地上到处是残肢碎尸，无处不是暗红色的血滴。你心中
忐忑不安，万分警惕，不知道从哪里就会窜出一个黑影。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"turen9",
		"south" : __DIR__"turen11",
		"west"  : __DIR__"turen7",
		"north" : __DIR__"turen4",
	]));
	set("no_learn", 1);

	setup();
}
int valid_leave(object me, string dir)
{
	if (! playerp(me))
		return ::valid_leave(me, dir);

	if (random(3))
	{
		write("你一下没看清楚路，摔了一了跤。\n");
		return -1;
	}
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
