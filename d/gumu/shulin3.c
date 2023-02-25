// shulin3.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这里是树林的边缘，参天古树已经很稀少了。东面有一座高山，
隐约看见山间云雾缭绕中，似乎有什么廊檐的建筑。山势缓和，但
山上郁郁葱葱地栽满了树木。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"south" : __DIR__"caodi",
		"northeast" : __DIR__"shulin2",
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
