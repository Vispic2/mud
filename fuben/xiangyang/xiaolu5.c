//by 秦始皇 qsh ednpc tools.
// xiaolu5.c

#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIC"蒙古包"NOR);
	set("qilin",1);
		set("exits", ([
		"west" : __DIR__"xiaolu8",
		"south" : __DIR__"xiaolu6",
	//	"north" : __DIR__"xiaojiuguan",
			"east" : __DIR__"xiaolu4",
	]));
set("objects", ([
			"/d/aaa/npc/menggubing" :1,
	]));
	set("long","");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
