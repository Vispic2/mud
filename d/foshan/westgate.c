//Room: /d/foshan/westgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","西门");
	set("long",@LONG
这里是佛山镇的西门。岭南以西经由广西可至大理。东面一条
东西向的大街是佛山镇的主要街道。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"street1",
	    "west"  : __DIR__"road7",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
