inherit ROOM;

void create()
{
  
    set("short", "墓室");
    set("long",@LONG
这是一间墓室。墓室顶上有一颗特别大的明珠闪闪发光。中央放着一副玉
棺，周围则堆放了无数的奇珍异玩。一张供桌摆在玉棺前，桌上放着一个香炉
及一个盘子 (panzi)。墓室对面挂这一幅青年少妇的画像。画像上的少妇巧笑
嫣然，和惨白的玉棺及碧油油的珠光形成了一幅奇诡的画面。忽然一阵阴风吹
过，你不禁打了一个寒颤。
LONG);
	set("item_desc", ([
		"panzi" : @TEXT
    你仔细看了一下盘子，这是一个玉盘，里面放着数颗晶莹的
    明珠。这些明珠似乎可以拿出来(pick zhu)。
TEXT
	]));

	set("exits", ([
		"up" : __DIR__"mudao",
	]));

	set("pick_available", 3 + random(3));
	setup();
}

void init()
{
	object me = this_player();

	add_action("do_pick","pick");
	me->set_temp("taohua/墓室", 0); 
}

int do_pick(string arg)
{
       object me,obj,killer;

       me = this_player();
       if (! arg || arg != "zhu")
	      return notify_fail("你要拿什么? \n");

       if (me->query("family/family_name") == "桃花岛")
	      return notify_fail("你是桃花岛弟子, 岂能偷岛主的东西? \n");

       if (query("pick_available") > 0)
       {
		message_vision("$N从盘子里拿出来一颗明珠。\n", this_player());
		obj = new (__DIR__"obj/mingzhu");
		obj->move(me, 1);
		add("pick_available", -1);
		me->start_busy(3);
		if (me->query_temp("taohua/墓室")) return 1;
		killer = new (__DIR__"npc/shoumu") ;
		message_vision("\n突然墓室中打开了一道暗门，从里面走出一个守墓家奴。\n"
			       "对$N喝道：贼子敢尔！连夫人的东西你也敢动！\n", me);
		killer->move(environment(me));
		killer->kill_ob(me);
		me->set_temp("taohua/墓室", 1);
       }
       return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
