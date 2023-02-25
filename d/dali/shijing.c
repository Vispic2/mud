//Room: /d/dali/shijing.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","石径");
	set("long",@LONG
你走在大理镇南王府中的石径上。路边长木遮天，微风习习，十
分凉爽。路南是一个碧绿透亮的小湖，水禽游鱼，映影其间。西边通
向大厅，东面好象是个花园。
LONG);
	set("objects", ([
	   __DIR__"npc/xianhe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"tingyuan",
	    "west"  : __DIR__"wfdating",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
