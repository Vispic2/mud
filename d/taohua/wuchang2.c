// wuchang2.c

inherit ROOM;

void create()
{
	set("short", "修行场");
	set("long", @LONG
这里是桃花岛弹指山庄修行的场所，大部分的桃花岛弟子武功有了
一定的根基以后就在这里苦修，领悟上乘武学。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"houyuan",
	]));

 	set("objects", ([
		"/clone/npc/mu-ren" : 4,
	]));

	set("for_family", "桃花岛");

	set("outdoors", "taohua");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
