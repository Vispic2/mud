inherit ROOM;

void create()
{
	set("short", "测试房间");
	set("long", @LONG
测试房间。
LONG);
	set("is_huanjing", 1);
	set("item_desc", ([
		"牌子":"千万不要飞出去，要不然你会死得很惨。\n",
		]));

	set("action_list", ([
		"离开" : "likai",
		]));
	set("no_clean_up_fb", 1);
	setup();
}

void init()
{
	add_action("do_disable", ({"zdsm","use", "fu", "eat", "exert", "fly", "walk", "flygo"}));
	add_action("do_likai", "likai");
}

int do_disable(string arg)
{
	object who = this_player();

	tell_object(who, "这里无法使用这个指令。\n");
	return 1;
}

int do_likai(string arg)
{
	if (!arg || arg == "")
	{
		write(ZJOBLONG + "你确定要离开副本吗？\n" + ZJOBACTS2 + "确定:likai y\n");
		return 1;
	}

	if (arg == "y")
	{
		query("mem")->end_fuben(query("mem"));
		return 1;
	}

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
