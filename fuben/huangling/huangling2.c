//by 秦始皇 qsh ednpc tools.
// huangling2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","皇陵墓道");
	set("long","这里是皇陵墓道，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"huangling8",
		"south" : __DIR__"shishi",
		"north" : __DIR__"huangling",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/ehun":1,	
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
