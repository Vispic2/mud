// yongdao2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
甬道忽然转弯，走了两三丈远，前面豁然空阔，出现一个洞穴，
便如是座石室。
LONG );
	set("exits", ([ /* sizeof() == 2 */
	    "north" : __DIR__"shandong",
	    "west"  : __DIR__"yongdao1",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
