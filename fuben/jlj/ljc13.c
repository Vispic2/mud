//by name qq:3468713544
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","垃圾场"NOR);
	set("long","这里是垃圾场");
	set("exits", ([
		"east" : "/fuben/jlj/ljc70",
		"west" : "/fuben/jlj/ljc66",
		"south" : "/fuben/jlj/ljc14",
		"north" : "/fuben/jlj/ljc12",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
