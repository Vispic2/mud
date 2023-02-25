#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
这里是万安寺的侧厅，地上摆着几个蒲团。
LONG );
	set("exits", ([
		"west" : __DIR__"was_zoulang1",
	]));

	set("outdoors", "beijing");
	setup();
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
