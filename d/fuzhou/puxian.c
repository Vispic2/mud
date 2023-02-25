// Room: /d/fuzhou/puxian.c
inherit ROOM;

void create()
{
	set("short", "莆仙平原");
	set("long", @LONG
你走在莆仙平原上。这里物产丰饶，人烟稠密，望北就
是福州府城了。往南就进入闽南。
LONG );
	set("exits", ([
		"north" : __DIR__"zhongzhou",
		"south" : "/d/quanzhou/beimen",
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
