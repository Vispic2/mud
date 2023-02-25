// /d/taohua/houyuan.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是山庄的后院。院后是桃花岛的唯一一座山峰：弹指峰。整个桃花山庄
倚山而立，险势天成。南边有两个露天小场，桃花岛的弟子来来往往，非常忙
碌，不少人衣衫尽湿，还有一些弟子鼻青脸肿、带伤而行。
LONG );
	set("outdoors", "taohua");
	set("exits", ([
		"north" :__DIR__"dating",
		"west"  :__DIR__"xiaowu",
		"east"  :__DIR__"siguoshi" ,
		"southeast" : __DIR__"wuchang1",
		"southwest" : __DIR__"wuchang2",
		"south" : __DIR__"wuchang3",
	]));

	set("objects", ([
		__DIR__"obj/shizi" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
