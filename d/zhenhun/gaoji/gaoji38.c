 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji37",
	"north" : __DIR__"gaoji39",
	"east" : __DIR__"gaoji35",
	"west" : __DIR__"gaoji53",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	"/d/zhenhun/npc/qiutu3b" : 1 + random(3),
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
