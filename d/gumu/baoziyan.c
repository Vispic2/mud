// baoziyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "抱子岩");
	set("long", @LONG
一路过来，山路是越来越险。只见光秃秃的山路，左旁尽是怪石，
而右则是万丈深渊，渺不见底。前方不远处的一块巨石，便是有名的
抱子岩。再看几眼，觉那岩生得甚是奇怪，就如一个妇人抱着个孩子
般，细心呵护。往南和西各是一片密林。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"      : __DIR__"shulin8",
		"south"     : __DIR__"shulin9",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/chen": 1,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
