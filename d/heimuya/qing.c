//ROM dating
inherit ROOM;
void create()
{
	set("short", "青龙堂大厅");
	set("long", @LONG
这是『日月神教』下第三大堂：青龙堂的大厅。一位长者居
中，神情恍惚。
LONG );
	set("exits", ([
	    "north" : __DIR__"chlang2",
	    "east" : __DIR__"tang",
	]));
	set("objects",([
	    __DIR__"npc/jiabu"   :1,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
