// cetang.c 侧堂
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "侧堂");
	set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青松山石的盆
景，墙壁上挂着一些字画。
LONG
	);
	set("exits", ([
		"east" : __DIR__"guozhendian",
		"west" : __DIR__"huizhentang",
		"north" : __DIR__"shiweishi",
		"south" : __DIR__"datang2",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/li" : 1,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
