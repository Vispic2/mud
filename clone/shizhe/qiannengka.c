// basic_sword.c

inherit ITEM;

void create()
{
	set_name(HIW"潜能卡"NOR, ({ "qiannengka", "ka" }));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",HIW"一张专门存潜能的卡，死亡后可以保护潜能丢失!，"ZJURL("cmds:potential_bank")ZJSIZE(20)"潜能银行"NOR"\n");
		set("value", 100);			  
     //   set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_sell", 1);
	//	set("no_steal", 1);
	//	set("no_beg", 1);
		set("material", "paper");
		set("action_list", ([
		"潜能银行":"potential_bank",
		
		]));
	}
	 	setup();
}
void init()
{
	add_action("do_potential_bank", "potential_bank");
}

int do_potential_bank(string arg)
{
	object who = this_player();
	string type;
	int num;
	
	if (!arg)
	{
		write(ZJOBLONG + "你要使用什么服务？\n" + ZJOBACTS2+ZJMENUF(3,3,8,30) + "存潜能:potential_bank cun"ZJSEP"取潜能:potential_bank qu"ZJSEP"查询:potential_bank check\n");
		return 1;
	}
	
	if (arg == "cun")
	{
		write(INPUTTXT("你目前有" + ((int)who->query("potential") - (int)who->query("learned_points")) + "潜能，你要存入多少潜能？", "potential_bank cun $txt#") + "\n");
		return 1;
	}
	
	if (arg == "qu")
	{
		write(INPUTTXT("你目前存有" + who->query("potential_bank/amount") + "潜能，你要取出多少潜能？", "potential_bank qu $txt#") + "\n");
		return 1;
	}
	
	if (arg == "check")
	{
		write(ZJOBLONG + "你目前存在潜能银行的潜能为" + who->query("potential_bank/amount") + "。\n");
		return 1;
	}
	
	if (sscanf(arg, "%s %d", type, num) == 2)
	{
		if (type == "cun" && num > 0)
		{
			if (((int)who->query("potential") - (int)who->query("learned_points")) < num)
				return notify_fail(ZJOBLONG + "你的潜能没那么多了。\n");
			if (!MONEY_D->player_pay(who, 1000))
				return notify_fail(ZJOBLONG + "你银子不足。\n");
			who->add("potential_bank/amount", num);
			who->add("potential", -num);
			write(ZJOBLONG + "你存入了" + num + "潜能，花费10两白银。\n");
			return 1;
		}
		else if (type == "qu" && num > 0)
		{
			if (who->query("potential_bank/amount") < num)
				return notify_fail(ZJOBLONG + "你存在潜能银行的潜能没那么多了。\n");
			if (!MONEY_D->player_pay(who, 1000))
				return notify_fail(ZJOBLONG + "你银子不足。\n");
			who->add("potential_bank/amount", -num);
			who->add("potential", num);
			write(ZJOBLONG + "你取出了" + num + "潜能，花费10两白银。\n");
			return 1;
		}
		else
		{
			write("请输入大于0的数。\n");
			return 0;
		}
	}
	else
	{
		write("输入格式错误，请重新输入。\n");
		return 0;
	}
}
int query_autoload() { return 1; }


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
