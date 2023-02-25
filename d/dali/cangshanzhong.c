//Room: /d/dali/cangshanzhong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","苍山中部");
	set("long",@LONG
你行走在苍山中部山颠，此间地形极险，两边山高入云，中间一
条崎岖不平的山路。路西不远一条大河自北略偏西方向南流过，隆隆
水声遥遥可闻，正是南诏名川--泸水。此路是自西川和土番入大理的
必经之途，时有客商过往。由此向南穿越苍山可抵下关城，北面不远
则是出苍山的山口。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"jianchuan",
	    "southwest"  : __DIR__"cangshanlu1",
	    "southeast"  : __DIR__"xiaguan",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
