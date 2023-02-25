// Room: /xiakedao/lin1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林，似乎有人在这里设计了一个迷阵，一走进
来，你就迷失了方向。
LONG );
	set("outdoors", "xiakedao");
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"lin2",
		"north" : __DIR__"haitan",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
