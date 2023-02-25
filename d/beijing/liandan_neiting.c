// liandan_neiting.c

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "回春堂内厅");
	set("long", @LONG
这里是回春堂药店的内厅，你一走进这里，发现药的气味比外面还要浓上
很多。你看见一个小童正在这里埋着头整理药材。
LONG );
	//set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/liandan_tongzi" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"huichuntang",
		"north": __DIR__"liandan_yaoshi",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
