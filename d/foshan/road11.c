//Room: /d/foshan/road11.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。岭南山林茂密，多产毒
虫，各位行路要十分小心。
LONG);
	set("objects", ([
	   __DIR__"obj/shikuai": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"road13",
	    "southwest" : __DIR__"road10",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
