// chanfang1.c 禅房
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是全真教弟子摆放兵器的禅房，地下杂乱地堆着一些剑，有
的已经锈纹斑斑了，有的还是锋利透亮，全真弟子练功的时候，就到
这里来挑选兵刃。
LONG
	);
	set("exits", ([
		"east" : __DIR__"chanfang2",
	]));
	set("objects", ([
		__DIR__"npc/obj/gangjian" : random(3),
		__DIR__"npc/obj/gangdao" : random(2),
		__DIR__"npc/obj/tiejia" : random(2),
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
