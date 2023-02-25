// Room: /d/fuzhou/nanmen.c
inherit ROOM;

void create()
{
	set("short", "福州南门");
	set("long", @LONG
这里是福州南门，似乎没什么人来往，也没有官兵在这里把守。
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
		"north" : __DIR__"nanmendou",
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
