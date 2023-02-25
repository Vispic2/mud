//by name qq:3468713544
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","垃圾场"NOR);
	set("long","这里是垃圾场");
	set("exits", ([
		"east" : "/fuben/jlj/ljc91",
		"west" : "/fuben/jlj/ljc90",
		"south" : "/fuben/jlj/ljc17",
		"north" : "/fuben/jlj/ljc15",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
