// Room: /lingzhou/neizai.c
// by Doing

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "将军府内宅");
	set("long", @LONG
这里是将军府的内宅，零零落落的有一些小瓦房，小路幽静，隐隐
约约的能够听见一些人在嬉笑玩耍。
LONG );
	set("exits", ([
		"north" : __DIR__"jiangjunyuan",
	]));

	set("objects", ([
		__DIR__"npc/hao" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
