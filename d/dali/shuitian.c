//Room: /d/dali/shuitian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","水田");
	set("long",@LONG
这是一片低洼平地的农田，除了田埂，全部都被水淹没着，一些
普麽部的妇女赤着脚在田里插秧。这个地区雨水充足，虽然没有江河
流过，无需特别的灌溉，每至春夏田里自然雨水溢满。
LONG);
	set("objects", ([
	   __DIR__"npc/cow": 1,
	   __DIR__"npc/nongfu1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"luwang",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
