// Room: /d/songshan/shandao2.c
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你走在嵩山山道，青松翠柏，山风岚雾，时来飘荡。远望山下
犬吠鸡啼，顿起仙凡之感。
LONG );
	set("exits", ([
		"northup"   : __DIR__"shuyuan",
		"southdown" : __DIR__"qimushi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
