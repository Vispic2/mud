// Room: /d/taishan/.c
inherit ROOM;

void create()
{
	set("short", "回马岭");
	set("long", @LONG
此处又名天关，到了这里，马匹已不能再前进。据说当年唐玄
宗上泰山封禅，来到这里，因陡峭难攀，累死了白马，要改乘小轿
上山。
LONG );
	set("exits", ([
		"northup" : __DIR__"ertian",
		"southdown" : __DIR__"shijin",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/jian-ke" : 1,
	]));
	set("outdoors", "taishan");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
