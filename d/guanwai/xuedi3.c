// /guanwai/xuedi3.c

inherit ROOM;

#include "gwxuedi.h"

void create()
{
	set("short", "雪地");
	set("long", @LONG
这里是一片白茫茫的雪地，一眼望不到边际。四周一个人影也没有，厚
厚的积雪踩起来发出咯吱的响声，大地上留下一串孤独的脚印。寒冷的北风
呼啸而过，吹得脸生痛。暗淡的太阳低悬在天边，显得那么苍白。
LONG );
	set("exits", ([
		"north"  : __DIR__"chuanchang",
		"west"   : __DIR__"xuedi2",
	]));
	set("outdoors", "guanwai");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
