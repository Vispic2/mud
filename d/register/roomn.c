inherit ROOM;

void create()
{
	set("short", "心狠手辣");
	set("long", @LONG
这里是一间小茅屋，屋内一位大汉坦胸露乳，正大碗酒、大块肉落
肚，看见你进来，只是略略一点头。从此方向进入阎罗殿转生将决定你今后的性格为【心狠手辣】。
LONG );
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/li" : 1,
	]));
	set("exits", ([
		"south"  : __DIR__"entry",
		"out"   : __DIR__"yanluodian",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	if (! objectp(ob = present("li zicheng", this_object())))
	{
		ob = new(__DIR__"npc/li");
		ob->move(this_object());
	}

	ob->check_leave(me, dir);
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
