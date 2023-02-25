// qingjing.c 清净居
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "清净居");
	set("long", @LONG
这里是全真七子之末，也是唯一的女弟子孙不二的居室。这房间
窗明几净，和她几位师兄的卧室大不相同。床上折叠着一件道袍，袍
上绣着一个骷髅头。这骷髅头可不是随便绣来吓人的，是当年王重阳
收孙不二为徒时，画了一副骷髅图案给她，意思是说人生苦短，得道
为安。孙不二感念师恩，就将这个骷髅图案绣在自己的道袍上。
LONG
	);
	set("exits", ([
		"north" : __DIR__"nairongdian",
	]));

	set("objects", ([
		CLASS_D("quanzhen") + "/sun" : 1,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
