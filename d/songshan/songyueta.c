
// Room: /d/songshan/songyueta.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "嵩岳寺塔");
	set("long", @LONG
嵩岳寺塔为密檐式砖塔，高达十余丈，外廓十二面，内室八方
四门，十五层密檐塔刹向上收紧，优美绝伦。
LONG );
	set("exits", ([
		"east" : __DIR__"songyuesi",
	]));
	set("objects", ([
		__DIR__"npc/ding" :1,
	]));
	set("outdoors", "songshan");
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
