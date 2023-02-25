// kongdi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这是终南山山腰处的一块空地，地势平坦。北面一条小路直攀山
璧而上，通往是终南山主峰。南边和西边一大片密林，只闻阵阵琴声
自林中传出。往北是一条山路。往南和西各有一条小径。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"     : __DIR__"shulin5",
		"south"    : __DIR__"shulin4",
		"northup"  : __DIR__"shanlu1",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
