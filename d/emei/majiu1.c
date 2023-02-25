//Room: majiu1.c 马厩

#include <room.h>
inherit TRANS_ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是草棚边的马厩，常年供应新鲜草料。据说此地民风淳朴，马夫们会把
马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人
上路。马厩中堆放著几堆草料，正中有一口泔槽。
    马厩雨檐下的烂木柱上钉着一块破木牌。
LONG);
	set("outdoors", "emei");
	set("no_fight", 1);
	set("objects", ([
		"/clone/horse/zaohongma": 1,
		"/clone/horse/huangbiaoma": 1,
		"/clone/horse/ziliuma": 1,
		"/clone/npc/mafu": 1,
	   
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"    : __DIR__"caopeng",
	]));
	setup();
	replace_program(TRANS_ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
