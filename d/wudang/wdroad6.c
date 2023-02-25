//Room: wdroad6.c
//Date: Feb.12 1998 By Javw

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是陕西境内的一条静悄悄的黄土路，两旁有些小土屋，疏疏落落
的。路上行人很少，都行色匆匆地向前赶路。
LONG);
	set("outdoors", "wudang");
	set("exits", ([
	    "south"      : __DIR__"house",
	    "southeast"  : __DIR__"wdroad5",
	    "west"       : __DIR__"wdroad7",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
