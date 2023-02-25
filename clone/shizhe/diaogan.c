inherit ITEM;

void finish(object who);

void create()
{
	set_name("特制钓竿", ({"diao gan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一根特制的钓竿，可以用来"+ZJSIZE(23)+ZJURL("cmds:fish_yujing")+"钓鱼"NOR"。\n");
		set("unit", "根");
		set("no_sell", 1);
		set("no_put", 1);
		set("value", 100000);
		set("tezhi", 1);
		set("no_sell",1);

        set("no_give",1);
        set("no_drop",1);
		set("action_list", ([
		"使用":"fish_yujing",
		]));
	}

	setup();
}

void init()
{
	if (interactive(this_player()) &&
	    environment() == this_player())
	{
		add_action("do_fish_yujing", "fish_yujing");
	}
}

int do_fish_yujing()
{
	object who = this_player();

	if (who->is_busy() || who->is_fighting())
	{
		write("你现在正忙，无法钓鱼。\n");
		return 1;
	}

	if (environment(who)->query("short") != "汉水南岸")
	{
		write("这里不能钓鱼丫，听说扬州的汉水南岸是个钓鱼的宝地。\n");
		return 1;
	}

	if ((who->query("nanan_fish_last_time") / 86400) != (time() / 86400))
	{
		who->delete("nanan_fish");
	}

	if (who->query("nanan_fish") >= 10)
	{
		write("你今天已经不能再钓鱼了。\n");
		return 1;
	}

	message_vision("$N轻轻一甩杆，只见水面上荡起了一个个圆圈，中间只有一个白色的浮子在随着水波荡漾。\n", who);
	who->start_busy((: call_other, __FILE__, "fishing" :), (: call_other, __FILE__, "halt_fish" :));
	who->set_temp("fishing", 1);
	who->set_temp("finish_sign", 0);
	who->set("nanan_fish_last_time", time());

	return 1;
}

int fishing(object who)
{
	object diaogan;
    
    if (objectp(environment()) && environment()->query("short"))
    {
        tell_object(find_player("name"), sprintf("测试节点%O\n二%O\n", who, environment(this_object())));
		who->delete_temp("fishing");
		who->delete_temp("fishing_sign");
		return 0;
    }
    
	if (environment(who)->query("short") != "汉水南岸")
	{
		who->delete_temp("fishing");
		who->delete_temp("fishing_sign");
		return 0;
	}

	if (!who->query_temp("fishing"))
	{
		who->delete_temp("fishing_count");
		who->delete_temp("fishing_sign");
		return 0;
	}

	if (!objectp(diaogan = present("diao gan", who)) || !diaogan->query("tezhi"))
	{
		who->delete_temp("fishing");
		who->delete_temp("finish_sign");
		who->delete_temp("fishing_count");
		write("你身上没有特制钓竿。\n");
		return 0;
	}

	if (who->query_temp("finish_sign"))
	{
		who->add("nanan_fish", 1);
		who->delete_temp("fishing");
		who->delete_temp("finish_sign");
		who->delete_temp("fishing_count");
		tell_object(who, "鱼鳔剧烈抖动，你猛地一拉鱼竿。\n");
		finish(who);
		return 1;
	}

	if (who->query_temp("fishing_count") < 50)
	{
		if (who->query_temp("fishing_count") % 10 == 0)
			write("微风轻轻的吹，水面荡起一层层细浪，就是没有鱼上钩。\n");
		who->add_temp("fishing_count", 1);
	}
	else
	{
		who->set_temp("finish_sign", 1);
		return 1;
	}

	return 1;
}

int halt_fish(object who)
{
	who->delete_temp("fishing");
	who->delete_temp("finish_sign");
	who->delete_temp("fishing_count");
	write("你停止了钓鱼。\n");
	return 1;
}

void finish(object who)
{
	object gift;
	object yujing;

	if (random(10) < 2)
	{
		yujing = new("/d/fuben_huanjing/yujing");
		yujing->move(environment(who));
		yujing->set("player_id", who->query("id"));
		write("你钓到了一只鱼精。\n");
		return ;
	}
	else
	{
		gift = new("/clone/vip/putao");
		if (objectp(gift))
		{
			gift->move(who);
			write("你获得了一个葡萄！\n");
			return ;
		}
	}
}

//int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
