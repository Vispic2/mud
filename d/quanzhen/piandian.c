// piandian.c 偏殿
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "偏殿");
	set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆
景，墙壁上挂着一些字画。
LONG
	);
	set("exits", ([
		"east" : __DIR__"nairongdian",
		"west" : __DIR__"xianzhentang",
		"north" : __DIR__"datang2",
		"south" : __DIR__"guangning",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/shen" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
