//ROOM: fen0.c
inherit ROOM;

void create()
{
	set("short", "风雷堂");
	set("long", @LONG
这里是日月神教教下第一大堂。这里距黑目崖不远，教下第
一大堂堂主童百威把掌此堂。
LONG);
	set("exits", ([
	    "north" :  __DIR__"grass1",
	]));
	set("objects",([
	    __DIR__ "npc/tongbw" :1,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
