//by 游侠 ranger's ednpc tools.
// xiuxishi.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"休息室"NOR);
	set("long","这里是休息室，管理员尚未设定本地详细描述。");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangb",
		"north" : __DIR__"lianwuchanga",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_jiaotou":1,
	//__DIR__"obj/baoxiang":1,	
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
