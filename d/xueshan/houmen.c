//      houmen.c 后门
inherit ROOM;

void create()
{
	set("short", "后门");
	set("long", @LONG
这是雪山寺的后门。一片破落而萧索模样。喇嘛们香
火也足，花用也大。这是后门，虽然未免寒酸，可也总可
以掖着。
LONG );
	set("exits", ([
	    "south" : __DIR__"houyuan",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
