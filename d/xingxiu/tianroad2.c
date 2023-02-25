// room: /d/xingxiu/tianroad1.c
inherit ROOM;

void create()
{
	set("short", "天山山路");
	set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片草原。
路尽头松林下一位壮汉正在长啸练功。北上就是人人害怕的灵鹫宫了.
LONG );
	set("exits", ([
	    "northwest" : "/d/lingjiu/shanjiao",
	    "northeast" : __DIR__"xxh1",
	    "south" : __DIR__"tianroad1",
	]));
	set("objects", ([
		"/kungfu/class/xingxiu/shihou" : 1,
		__DIR__"npc/gushou"  : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
	]));
	set("outdoors", "xingxiu");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
