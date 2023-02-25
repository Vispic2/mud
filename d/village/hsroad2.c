// hsroad2.c
inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，南边隐约可见到扬州城的城墙。北面两条土路分
岔通向山里。
LONG );
	set("outdoors", "village");
	set("exits", ([
		"south"     : __DIR__"hsroad1",
		"northwest" : __DIR__"hsroad3",
		"northeast" : "/d/huashan/jzroad1",
	]));

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
