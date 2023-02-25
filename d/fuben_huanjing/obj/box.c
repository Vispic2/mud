inherit ITEM;

void create()
{
	set_name("宝箱", ({ "box" }));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个宝箱。"+ZJSIZE(25)+ZJURL("cmds:open_box")+"打开"+NOR+"\n");
		set("value", 1000);
		set("no_get",1);
		set("no_drop",1);
		set("do_not_clean_me", 1);
	}
	setup();
	set("action_list", ([
			"开启" : "open_box " + file_name(this_object()),
			]));
}

void init()
{
	add_action("do_open_box", "open_box");
}

int do_open_box(string arg)
{
	string * gift_file = ({
		//"/clone/shizhe/putao",
		"/clone/vip/dan_chongmai1",
		"/clone/shizhe/dan_chongmai2",
		"/clone/shizhe/dan_chongmai3",
		"/clone/shizhe/dan_chongmai4",
		"/clone/shizhe/putao1",
		//"/clone/vip/butian",
		//"/clone/vip/tiancs",
		"/clone/shizhe/jinsha",	
		"/clone/shizhe/tianling",
		"/clone/shizhe/cjj",  
		//"/clone/vip/cjj",   
	
	});
	object gift;
	object who = this_player();

	//if (arg != file_name(this_object()))
	//	return 0;

	if (query("open_sign"))
	{
		write("你已经打开了这个宝箱了。\n");
		return 1;
	}

	if (query("gift_sign"))
	{
		set("open_sign", 1);
		environment(who)->query("mem")->add("box_open_count", 1);
		if (who->query_temp("open_bad_box"))
			who->add_temp("open_bad_box", -1);

		if (objectp(gift = new(gift_file[random(sizeof(gift_file))])))
		{
			tell_object(who, "恭喜你获得了" + gift->query("name") + "。\n");
			gift->move(who);
			return 1;
		}
	}
	else
	{
		set("open_sign", 1);
		who->start_busy(5);
		if (!who->query_temp("open_bad_box"))
		{
			who->add_temp("open_bad_box", 1);
			tell_object(who, "你打开的是假的宝箱，一股烟雾喷出，你中毒了！\n");
			return 1;
		}
		else if(who->query_temp("open_bad_box") < 21)
		{
			who->add_temp("open_bad_box", 1);
			tell_object(who, "你打开的是假的宝箱，你中的毒加深了。\n");
			return 1;
		}
	}

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
