 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji3",
	"north" : __DIR__"gaoji8",
	"east" : __DIR__"gaoji4",
	"west" : __DIR__"gaoji35",
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