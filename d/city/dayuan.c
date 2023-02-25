// Room: /city/dayuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "财主大院");
	set("long", @LONG
你走进大院，迎面是一个假山水池，池上摆着一块奇形怪状的石头，据说
是当年花石纲的遗石。水池的两旁种满了花草。东边是一棵槐树，郁郁葱葱，
遮盖了大半个院子，显得阴森恐怖。一条长廊走道通往后院，有几个家丁把守。
LONG );
	set("exits", ([
		"south" : __DIR__"houyuan",
		"north" : __DIR__"caizhu",
	]));
	set("objects", ([
		__DIR__"npc/guanjia" : 1,
		__DIR__"npc/jiading" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
