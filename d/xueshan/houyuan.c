//      houyuan.c 后院
inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是雪山寺的后院，后院不大，栽了几株参天雪松，
在白晃晃的雪山背景下，竟是飘然出世的心动。南边是练
武场，北边是后门。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"eastdown" : __DIR__"dilao",
		"north" : __DIR__"houmen",
		"south" : __DIR__"chang3",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
