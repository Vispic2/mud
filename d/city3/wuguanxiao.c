// Room: wuguanxiao.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "金牛武馆三部");
	set("long", @LONG
这里是「金牛武馆」教授三部，师傅萧飞教授如下技能：基本轻
功，基本内功，基本招架，基本指法，基本暗器。
LONG );
	set("objects", ([
		__DIR__"npc/xiaofei" : 1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"wuguan",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
