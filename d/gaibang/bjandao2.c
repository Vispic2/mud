// Room: /d/gaibang/bjandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG );
	set("exits", ([
		"north" : __DIR__"underbj",
		"south" : __DIR__"bjandao1",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/quan-gq" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
