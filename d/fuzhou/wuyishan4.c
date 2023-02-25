// Room: /d/fuzhou/wuyishan4.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "天心岩");
	set("long", @LONG
天心岩为武夷名胜，岩下永乐寺为天下著名禅林。山腰“大
红袍”岩茶为天下极品，驰名海内外。
LONG );
	set("exits", ([
		"southeast" : __DIR__"wuyishan5",
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
