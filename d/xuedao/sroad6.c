// sroad6.c
inherit ROOM;
void create()
{
	set("short", "大雪山口");
	set("long", @LONG
冰天雪地，寒风刺骨。不是内力高深的人，已然经受不住了。
LONG );
	set("exits", ([
		"northdown" : __DIR__"sroad5",
		"westup"    : __DIR__"sroad7",
	]));
	set("outdoors", "xuedao");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
