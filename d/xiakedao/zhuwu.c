// zhuwu.c

inherit ROOM;

void create()
{
	set("short", "竹屋");
	set("long", @LONG
这是一个用碗口粗大的竹子搭建的屋子，离地不足三尺。有一小竹梯
搭在门口。
LONG );
	set("exits", ([
		"east" : __DIR__"haibin",
		"west": __DIR__"zhuwu2",
	]));
	set("outdoors", "nanhai");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
