//Room: /d/dali/chahuashan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花山");
	set("long",@LONG
你走在茶花山上，这里遍地是生长茂盛的茶花。当然，大部
分是凡品，但偶尔也会有一两株佳品藏匿其中。北望不远是大理
城的西门，东边不远是城墙。
LONG);
	set("objects", ([
	   __DIR__"obj/shanchahua": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"     : __DIR__"chahuashan3",
	    "south"     : __DIR__"chahuashan4",
	    "east"      : __DIR__"chahuashan5",
	    "westdown"  : __DIR__"chahuashan1",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
