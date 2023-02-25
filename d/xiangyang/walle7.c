// Room: /d/xiangyang/walle7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "东城头");
	set("long", @LONG
这里是襄阳的东城头。一些宋兵正在城头巡逻，一个牙将
正在这儿负责接受各种守城材料，一些弓箭手正拈弓搭箭紧盯
着城下的动静。
LONG );
	set("outdoors", "xiangyang");

	set("exits", ([
		"southwest" : __DIR__"walls8",
		"northdown" : __DIR__"walle5",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
