//Room: /d/foshan/eastgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","东门");
	set("long",@LONG
这里是佛山镇的东门。再往东走就要离开佛山，去往福建了。
西面一条东西向的大街是佛山镇的主要街道。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"road8",
	    "west"  : __DIR__"street5",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
