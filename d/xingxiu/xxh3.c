// Room: /d/xingxiu/xxh3.c
// Jay 3/18/96

inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里通向星宿海的深处。
LONG );
	set("objects", ([
		"/kungfu/class/xingxiu/tianlang"  : 1,
	]) );
	set("exits", ([
	     "southwest" : __DIR__"xxh2",
	     "northwest" : __DIR__"xxh5",
	]));
	set("outdoors", "xingxiu");
	setup();
}



/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
