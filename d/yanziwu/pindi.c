//ROOM: /d/yanziwu/pindi.c

inherit ROOM;

void create()
{
	set("short", "品笛庭");
	set("long",@LONG
只见墙上挂有萧管之类的乐器，桌上放有一沓乐谱，想是慕容世家
演练乐曲的所在了。在向西就到了太湖岸边，向东则是慕容世家接待宾
客的龙凤厅了。
LONG );
	set("exits", ([
	    "east"  : __DIR__"longfeng",
	    "west"  : __DIR__"bozhou",
	]));

	set("objects", ([
	 	__DIR__"npc/gongye"  : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (dir != "east")
		return 1;

	if (guarder = present("gongye qian", this_object()))
		return guarder->permit_pass(me, dir);

	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
