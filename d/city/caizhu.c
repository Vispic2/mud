// Room: /city/caizhu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "财主大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门两
侧，朱漆大门足足有三寸厚。门上挂着两个灯笼，写着“崔”字。崔家是当地
首富，而且以蛮横著称。几条狼狗嚎叫着向你冲了过来。
LONG );
	set("exits", ([
		"north" : __DIR__"xidajie2",
		"south" : __DIR__"dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
