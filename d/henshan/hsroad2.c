// Room: /d/henshan/hsroad2.c 黄土路
// Modified by Java on Feb.14 1998

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northwest" : __DIR__"hsroad1",
		"southwest" : __DIR__"hsroad3",
		"southeast" : "/d/fuzhou/fzroad7",
	]));

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
