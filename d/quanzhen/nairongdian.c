// nairongdian.c 乃容殿
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "乃容殿");
	set("long", @LONG
这里是大堂旁边的一个侧殿，也是接待重要客人的地方。殿不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆
景，墙壁上挂着一些字画。
LONG
	);
	set("exits", ([
		"south" : __DIR__"qingjing",
		"west" : __DIR__"piandian",
		"north" : __DIR__"datang3",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/cheng" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
