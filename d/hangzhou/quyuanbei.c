// quyuanbei.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "曲院风荷");
	set("long", @LONG
跨过小拱桥，迎面有一亭院，旁边立着石碑，上题“曲院风荷。”
往东是回苏堤。
LONG);
	set("exits", ([
	    "east"     : __DIR__"suti2",
	    "enter"    : __DIR__"quyuanfenghe",
	]));
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
