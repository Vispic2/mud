// Room: /d/fuzhou/fzroad9.c
inherit ROOM;

void create()
{
	set("short", "闽中大道");
	set("long", @LONG
你走在闽江北岸大道上。福建境内无山不青，无水不翠，山
陡林深少行人，不禁让你惴惴。北面有股青烟冒起，似乎有家野
店。
LONG );
	set("exits", ([
		"northwest" : __DIR__"fzroad8",
		"north"     : __DIR__"fzroad10",
		"east"      : __DIR__"fzroad11",
	]));
	set("objects", ([
		"/d/qingcheng/npc/jia" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
