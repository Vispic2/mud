// by name QQ：21315491
//矿区 2021.5.27
inherit ROOM;
void create()
{
	set("short", "矿区基地");
	set("long", "这里四周都是采取资源的好地方，快去探索一下吧！\n");	
	set("exits", ([	
    "north" : __DIR__"shulin",
    "south" : __DIR__"guwu",
    "west" : __DIR__"shiliao",
    "east" : __DIR__"tieliao",
	]));
	set("no_fight", 1);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
