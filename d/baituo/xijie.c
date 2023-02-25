//xijie

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long",
	     "这里是小镇的西街。北边有个酒店，门前树立着高高的旗\n"
	 "杆，一块青布幌子迎风飘扬，上面印着朱红色的大字‘酒’。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"bridge",
		"east" : __DIR__"dongjie",
		"north" : __DIR__"jiudian",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
		__DIR__"npc/snaker"  :1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
