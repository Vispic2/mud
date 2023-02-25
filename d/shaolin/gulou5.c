// Room: /d/shaolin/gulou5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "鼓楼五层");
	set("long", @LONG
一眼望去，只见蓝天白云，青山列列，令人将尘俗之气，
顿为一一扫。南至前三殿，北到方丈楼，整个少林寺尽在眼底。
北面竹林随风起伏，犹如一片竹海。东西面围绕全寺的是密密
匝匝的松林，一眼往不到边。
LONG );
	set("exits", ([
		"up" : __DIR__"gulou6",
		"down" : __DIR__"gulou4",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
