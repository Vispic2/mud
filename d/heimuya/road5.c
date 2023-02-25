// road5.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条黄土路上。这里已经是陕西地面了，向南一条黄
土大道，两边望不尽的黄土高坡，没有一丝吝啬的绿色。东北隐
隐传来流水的声响。
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"northeast" : "/d/huanghe/weifen",
		"south"     : __DIR__"road6",
	]));

	set("objects", ([
		__DIR__"npc/seller" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
