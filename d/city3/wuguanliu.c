// Room: wuguanliu.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "金牛武馆四部");
	set("long", @LONG
这里是「金牛武馆」教授四部，师傅刘虹瑛教授如下技能：基本
轻功，基本内功，基本招架，基本掌法，基本剑法。
LONG );
	set("objects", ([
		__DIR__"npc/liuhongying" : 1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"wuguan",
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
