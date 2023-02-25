// Room: /d/quanzhou/beimen.c
inherit ROOM;

void create()
{
	set("short", "泉州北门");
	set("long", @LONG
这里是南方第一港泉州的北门。出此门向北可抵中原。
LONG );
	set("exits", ([
		"north" : "/d/fuzhou/puxian",
		"south" : __DIR__"zhongxin",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
