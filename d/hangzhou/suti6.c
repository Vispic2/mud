// suti6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "苏堤");
	set("long", @LONG
秋月之夜，月下观湖，满湖银波粼粼，阵阵微风，风中桂子飘香，
令人为之心醉。堤边泊着小舟是送游客去三潭映月的。往西边是去
花港，东面可见三潭映月遥立湖中，北边是锁澜桥，南面映波桥。
LONG);
	set("exits", ([
	    "north"     : __DIR__"suti5",
	    "south"     : __DIR__"suti7",
	    "west"      : __DIR__"huagang",
	]));
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
