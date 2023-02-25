//Room: wdroad7.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里一条静悄悄的黄土路，两旁有些小土屋，疏疏落落的。路上行人
很少，都行色匆匆向前赶路。
LONG);
	set("outdoors", "wudang");
	set("exits", ([
	    "east"      : __DIR__"wdroad6",
	    "southwest" : __DIR__"wdroad8",
	]));
	set("no_clean_up", 0);
	setup();
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
