//by 秦始皇 qsh ednpc tools.
// bingying6.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","蒙古兵营");
	set("long","这里是蒙古兵营，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"bingying8",
		"south" : __DIR__"bingying7",
		"west" : __DIR__"qianshao",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/bing":2,	
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
