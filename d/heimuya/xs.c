//by 游侠 ranger's ednpc tools.
// xs.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小舍");
	set("long","这里是小舍，管理员尚未设定本地详细描述。");
	set("exits", ([
		"south" : __DIR__"huoting",
	]));
	set("objects", ([
		__DIR__"npc/dongfang" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
