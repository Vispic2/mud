 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji42",
	"north" : __DIR__"gaoji44",
	"east" : __DIR__"gaoji30",
	"west" : __DIR__"gaoji48",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
