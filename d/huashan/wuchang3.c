// wuchang3.c

inherit ROOM;

void create()
{
	set("short", "东练武场");
	set("long", @LONG
这里是华山派的练武场，场上立这几个木人，地处偏僻，有些荒凉。
LONG );
	set("exits", ([ /* sizeof() == 2 */
	    "west"     : __DIR__"wuchang1",
	]));
	set("objects", ([
	    "/clone/npc/mu-ren" : 3,
	]));
	set("outdoors", "huashan");

	set("for_family", "华山派");

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
