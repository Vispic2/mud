// Room: /d/xiangyang/walle3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是登向城头的石阶，因为城墙很高，所以很陡。石阶两
侧有可供拉车上下的斜坡道。
LONG );
	set("outdoors", "xiangyang");
	set("exits", ([
		"southup"   : __DIR__"walle5",
		"northdown" : __DIR__"walle1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int c_skill;

	me = this_player();
	if (sscanf(dir, "%*sup") == 1)
	{
		c_skill = me->query_skill("dodge", 1);
		if (me->query("qi") > 40)
		{
			me->receive_damage("qi", 20 + random(20));
			if (me->can_improve_skill("dodge") && c_skill < 100)
				me->improve_skill("dodge", 1 + random(me->query("dex")));
		} else
		{
			me->set("qi", 0);
			return notify_fail("你太累了，还是休息一会儿吧。\n");
		}
	}
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
