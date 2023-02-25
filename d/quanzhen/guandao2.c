// guandao2.c 官道
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条官府修建的大道，西面隐约可以看见武功镇的东门。
远处好象可以看见巍峨的城墙。往东是通往中原的路。走在这里，
你似乎有了一种‘劝君更进一杯酒，西出阳关无故人’的感觉。
LONG
	);
	set("outdoors", "wugong");
	set("exits", ([
		"east" : __DIR__"guandao1",
		"west" : __DIR__"dongmen",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
