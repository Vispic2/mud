// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit BUILD_ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
南面就是苏州城了。
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"south"     : __DIR__"beimen",
		"southwest" : __DIR__"huqiu",
		"northwest" : "/d/guiyun/shanlu2",
	]));

	set("max_room", 3);

	setup();
	replace_program(BUILD_ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
