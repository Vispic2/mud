// xiaodao5.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条从南到北的林间小道，沿途风景极之清幽，参天古树，拔地而
起，两旁百花争艳。令人留连忘返。
LONG );
	set("exits", ([
		"south" : __DIR__"muwu1",
		"north" : __DIR__"qingcaop",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
