// Room: /city/biaojuhy.c
inherit ROOM;

void create()
{
	set("short", "镖局后院");
	set("long", @LONG
镖局后院是平常镖师们打拳练功之所，除了几个木桩石
锁外，别无它物。
LONG );
	set("exits", ([
		"south" : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
