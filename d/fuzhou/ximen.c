// Room: /d/fuzhou/ximen.c
inherit ROOM;

void create()
{
	set("short", "福州西门");
	set("long", @LONG
这里是福州西门。出此门向西可达中原。
LONG );
	set("exits", ([
		"east" : __DIR__"ximendajie",
		"west" : __DIR__"fzroad11",
	]));
	set("outdoors", "fuzhou");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
