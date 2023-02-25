// Room: /d/xingxiu/xxroad4.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条在山壁上人工开凿出来崎岖的小路上，这里，寒风凛冽，西面
是望不见底的深涧。
LONG );
	set("exits", ([
	    "southdown" : __DIR__"tianroad3",
	    "north" : __DIR__"xxroad5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
