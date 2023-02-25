// xianzhentang.c 显真堂
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "显真堂");
	set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不大，
只摆放着一张桌子和几把椅子。桌上摆放着一盆高山流水的盆景，墙
壁上挂着一些字画。西面有一间药剂室，是配药的地方。
LONG
	);

	set("exits", ([
		"east" : __DIR__"piandian",
		"west" : __DIR__"yaojishi",
		"north" : __DIR__"datang1",
		"south" : __DIR__"rongwutang",
	]));
	set("objects",([
	      CLASS_D("quanzhen") + "/zhang" : 1,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
