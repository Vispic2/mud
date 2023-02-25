// Room: /d/songshan/fawangsi.c
inherit ROOM;

void create()
{
	set("short", "法王寺");
	set("long", @LONG
法王寺在嵩山玉柱峰下，隐约于茂密松林中，此地素有 "嵩山
第一胜地" 之称。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao4",
		"northeast" : __DIR__"shandao5",
		"northup"   : __DIR__"tayuan",
		"west"      : __DIR__"yuetai",
	]));
	set("objects", ([
		__DIR__"npc/zhong" : 1,
		__DIR__"npc/deng" : 1,
		__DIR__"npc/gao" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
