// Room: by寒江雪
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIY"魂帝主殿"NOR);
	set("long", @LONG
这里就是本副本大boss击杀可以获得丰富奖励！
LONG
	);
	set("exits", ([
		"south" : __DIR__"h11",
		"north" : __DIR__"h9",
	]));
	set("objects", ([
		__DIR__"npc/h": 1,
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
