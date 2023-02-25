// Room: /city/biaojudy.c
inherit ROOM;

void create()
{
	set("short", "镖局大院");
	set("long", @LONG
大院里显得有些凌乱，趟子手和镖师们进进出出，似乎
都在满地里忙碌着什么。一棵很大的榕树栽在院子中央，给
火辣辣的福州带来一点凉爽。
LONG );
	set("exits", ([
		"south"   : __DIR__"biaoju",
		"north" : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
