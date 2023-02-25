// Room: /d/xiangyang/juyilianwu2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "练功场");
	set("long", @LONG
这里是聚义馆中用来练功的地方。有几个人正在专心致致
地练武，有几个手持兵器，在互相拆招。身法灵动，犹如穿花
蝴蝶一般，你不禁看花了眼，别的人则坐在地上的蒲团上苦练
内力。
LONG );
	set("outdoors", "xiangyang");

	set("exits", ([
		"east" : __DIR__"juyiyuan",
	]));
	set("objects", ([
		"/clone/npc/tong-ren" : 3,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
