//      midao.c 密道
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
这是一条狭窄的暗道。阴森可怕，到处积满了灰尘，
结满了蛛网，也不知道通往何处。
LONG );
	set("exits", ([
		"north" : __DIR__"mishi",
		"east" : __DIR__"neidian",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
