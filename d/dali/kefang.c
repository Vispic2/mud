//Room: /d/dali/kefang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","客房");
	set("long",@LONG
这是一间客房，靠墙放了一张梨木大床，上面的被褥尽是苏
绣，工美绝伦。正中放了一张八仙桌，几个奇服南人正在高谈阔
论。
LONG);
	set("objects", ([
	   __DIR__"npc/peicong": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"zoulang2",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
