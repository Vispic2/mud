//by 秦始皇 qsh ednpc tools.
// chasi.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"茶肆"NOR);
	set("long","这里是茶肆，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"xiaolu7",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/shouling":1,
		//"fuben/wuguan/obj/baoxiang2":1,	
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
