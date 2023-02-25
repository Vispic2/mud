//Room: shierpan4.c 十二盘
inherit ROOM;

void create()
{
      set("short","十二盘");
      set("long",@LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东下则到万
年庵。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "northeast" : __DIR__"shierpan3",
	  "southwest"	: __DIR__"huayanding",
      ]));
      setup();
}

int valid_leave(object me, string dir)
{
	int c_skill;

	me = this_player();
	if (dir == "southwest")
	{
		c_skill = me->query_skill("dodge", 1);
		if (me->query("qi") > 40)
		{
			me->receive_damage("qi", 20 + random(20));
			if (me->can_improve_skill("dodge") && c_skill < 100)
			   me->improve_skill("dodge", 1 + me->query_skill("dodge", 1) / 15);
			tell_object(me,"你爬上八十四盘，有些累了。\n");
		} else
		{
			me->set("qi", 0);
			tell_object(me, "你太累了，再也走不动了。\n");
			return -1;
		}
      }
      return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
