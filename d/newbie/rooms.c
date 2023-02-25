// regiser: roome.c
// by Doing

inherit ROOM;

void create()
{
	set("short", "狡黠多变");
	set("long", @LONG
这里是一间小瓦房，布置的非常舒适，一小鬼舒舒服服的靠在椅子
上，轻摇羽扇，有如关羽之长，宛若诸葛之亮。正笑吟吟的看着你进来。从此方向进入阎罗殿转生将决定你今后的性格为【狡黠多变】。
LONG );
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/wei" : 1,
	]));
	set("exits", ([
		"north"  : __DIR__"entry",
		"out"   : __DIR__"yanluodian",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	if (! objectp(ob = present("wei xiaobao", this_object())))
	{
		ob = new(__DIR__"npc/wei");
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
