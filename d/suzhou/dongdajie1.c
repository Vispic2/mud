// Room: /d/suzhou/dongdajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东大街
的延伸，南面是苏州城里一个老字号的当铺，北面是一条小胡
同。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"dongdajie2",
		"north"     : __DIR__"hutong1",
		"south"     : __DIR__"dangpu",
		"southwest" : __DIR__"baodaiqiao",
		"northwest" : __DIR__"canlangting",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
