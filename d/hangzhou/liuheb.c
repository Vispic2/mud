// liuheb.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "六和塔");
	set("long", @LONG
这里是六和塔的十一层。窗(window)外是浓妆淡抹的西子湖，塔
中玲珑八角，青砖砌地，雕栏飞檐间粘连了些许蛛网。
LONG);
	set("exits", ([
	    "down"  : __DIR__"liuhea",
	    "up"    : __DIR__"liuhec",
	]));
	set("objects", ([
	    __DIR__"honghua/lu" :1,
	]));
	set("item_desc", ([
	    "window": "从窗口望出去，钱江东去。近处农田中，有一农夫正荷锄耕耘。\n",
	]));
	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "up" &&
	    objectp(present("lu feiqing", environment(me))))
	    return notify_fail("陆菲青用冷森森的眼光扫了你一眼，你迈向楼梯的脚吓了一哆嗦。\n");
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
