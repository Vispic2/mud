inherit ROOM;

void create()
{
	set("short", "光明磊落");
	set("long", @LONG
这里是一间小竹屋，朴素异常，屋中立着一位气宇轩昂的大汉，正
满怀笑意的看着你。从此方向进入阎罗殿转生将决定你今后的性格为【光明磊落】。
LONG );
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
	set("exits", ([
		"west"  : __DIR__"entry",
		"out"   : __DIR__"yanluodian",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	if (! objectp(ob = present("lu tianshu", this_object())))
	{
		ob = new(__DIR__"npc/lu");
		ob->move(this_object());
	}

	ob->check_leave(me, dir);
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
