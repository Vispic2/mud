// wuchang2.c

inherit ROOM;

void create()
{
	set("short", "北练武场");
	set("long", @LONG
这里是华山派的练武场，场上立这几个木人，南面是另一个练武场，
到处是华山的弟子人来人往，热闹非凡。
LONG );
	set("exits", ([ /* sizeof() == 2 */
	    "south"     : __DIR__"wuchang1",
	]));
	set("objects", ([
	    "/clone/npc/mu-ren" : 4,
	]));
	set("outdoors", "huashan" );
	set("for_family", "华山派");

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
