// shandong1.c
inherit ROOM;
void create()
{
	set("short", "山洞");
	set("long", @LONG
空空荡荡一个山洞，倒也还算干净，尽头摆了一张石床。
LONG );
	set("exits", ([
		"out" : __DIR__"sroad8",
	]));
	set("objects", ([
		__DIR__"obj/dachang" :1,
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
