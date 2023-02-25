// room: well.c
// Jay 4/8/96

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
	set("short", "井中");
	set("long", @LONG
这是在一口枯井中。光线极暗，什么也看不清。
LONG );
	set("exits", ([
		"up" : __DIR__"houyuan",
		"down" : __DIR__"well1",
	]));
	setup();
}

void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me;

	me = this_player();
	if (! arg || arg == "") return 0;
	if (! present("fire", me)) return 0;
	if (arg == "fire")
	{
		write("你点燃了火折，发现井壁上有一道裂缝，似乎可以钻(zuan)出去。\n");
		me->set_temp("marks/钻1", 1);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me;

	me = this_player();
	if (me->query_temp("marks/钻1"))
	{
		message("vision", me->name() + "滋溜一下不见了。\n",
			environment(me), me);
		me->move(__DIR__"midao");
		message("vision", me->name() + "从井里钻了出来。\n",
			environment(me), me);
		me->delete_temp("marks/钻1");
		return 1;
	}

	write("你想往哪儿钻？！\n");
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
