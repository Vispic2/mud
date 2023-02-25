 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji40",
	"north" : __DIR__"zhongji42",
	"east" : __DIR__"zhongji32",
	"west" : __DIR__"zhongji50",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
