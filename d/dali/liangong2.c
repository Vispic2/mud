// liangong2.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里摆着一些铜人，他们比木人更加结实，也就不容易坏，因此
也是高手修炼上乘绝艺的地方。向南走穿过练功场就是王府内院。
LONG );
	set("exits", ([
		"south" : __DIR__"liangong",
		"north" : __DIR__"liangong3",
	]));
	set("objects", ([
		"/clone/npc/tong-ren": 4,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
