// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "醉仙楼大堂");
	set("long", @LONG
这是醉仙楼大堂，来来往往的人客和跑堂小二，夹杂着三个宴会厅
刺耳的呼叫声，碰杯声，打闹声，赖酒声，热闹非凡。你在三个宴会厅
前打量着进哪个凑个热闹，蹭点白食。
    东边是玫瑰厅，朝南的是牡丹厅，向北是芙蓉厅。
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"west"   : __DIR__"zuixianlou2",
	]));
	set("no_fight","1");
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
