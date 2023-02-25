// banker.c 银行家

#include <dbase.h>
#include <ansi.h>

int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
	if (!total || total < 0)
	{
		this_player()->set("balance", 0);
		write(ZJOBLONG"您在敝商号没有存钱。\n");
		return 1;
	}
	write(ZJOBLONG+this_object()->query("name")+"悄悄告诉你：您在弊商号共存有" + MONEY_D->money_str(total) + "。\n");
	return 1;							       
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;

	me = this_player();						     

	if (me->is_busy())
		return notify_fail("你还是等有空了再说吧！\n");

	if (this_object()->is_fighting())
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if (! arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
	   	return notify_fail("命令格式：convert|duihuan <数量> <货币单位> to <新货币单位>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (! to_ob && file_size("/clone/money/" + to + ".c") < 0)
	   	return notify_fail("你想兑换成什么？\n");

	if (! from_ob)
	   	return notify_fail("你身上没有带这种钱。\n");

	if (from_ob == to_ob)
		return notify_fail("你有毛病啊？\n");

	if (amount < 1)
	   	return notify_fail("你想白赚啊？\n");

	if ((int)from_ob->query_amount() < amount)
	   	return notify_fail("你带的" + from_ob->query("name") + "不够。\n");

	bv1 = from_ob->query("base_value");
	if (! bv1)
	   	return notify_fail("这样东西不值钱。\n");

	bv2 = to_ob ? to_ob->query("base_value")
		    : call_other("/clone/money/" + to, "query", "base_value");
	if (bv1 < bv2)  amount -= amount % (bv2 / bv1);
	if (amount == 0)
	   	return notify_fail("这些" + from_ob->query("name") + "不够换。\n ");

	if (bv1 > bv2 && bv1 / bv2 * amount > 10000)
		return notify_fail("哦呦...我这一下子还拿不出这么多散钱...\n");

	// allowed to convert now
	me->start_busy(1);

	from_ob->add_amount(-amount);

	if (! to_ob)
	{
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 / bv2);
		to_ob->move(me, 1);
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
			       chinese_number(amount),
			       from_ob->query("base_unit"),
			       from_ob->query("name"),
			       chinese_number(amount * bv1 / bv2),
			       to_ob->query("base_unit"),
			       to_ob->query("name")), me);

	return 1;
}									       

int do_deposit(string arg)						      
{
	string what,str;
	int amount, money_limit,i;
	object *inv,what_ob, me,obj;

	me = this_player();

	if (me->is_busy())
		return notify_fail("你还是等有空了再说吧！\n");

	if (this_object()->is_fighting())
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if (!arg)
	{
		inv = all_inventory(me);
		str = ZJOBACTS2+ZJMENUF(1,1,8,30);
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i]->query("money_id"))
			{
				if(str!=ZJOBACTS2+ZJMENUF(1,1,8,30))
					str += ZJSEP+inv[i]->short()+":cun "+inv[i]->query("id");
				else
					str += inv[i]->short()+":cun "+inv[i]->query("money_id");
			}
		}
		if(str==ZJOBACTS2+ZJMENUF(1,1,8,30))
		{
			write(ZJOBLONG"你身上没什么钱，你要存什么？\n");
		}
		else
		{
			write(ZJOBLONG"请选择要存的货币：\n"+str+"\n");
		}
		return 1;
	}

	if (sscanf(arg, "%d %s", amount, what) != 2)
	{
		if (! objectp(obj = present(arg, me)))
			return notify_fail(ZJOBLONG"你要存什么？\n");
		write(INPUTTXT("你共有"+obj->short()+"，你想存多少？","cun $txt# "+ arg)+"\n");
		return 1;
	}

	what_ob = present(what + "_money", me);
	if (! what_ob)
		return notify_fail("你身上没有带这种钱。\n");

	if (amount < 1)
		return notify_fail("你想存多少" + what_ob->query("name") + "？\n");

	if ((int)what_ob->query_amount() < amount)
		return notify_fail("你带的" + what_ob->query("name") + "不够。\n");

	// deposit it
	me->start_busy(1);

	if (me->query("balance") >= 1000000000)
		return notify_fail("你的存款已达上限。\n");


	message_vision(sprintf("$N拿出%s%s%s，存进了银号。\n",
	chinese_number(amount), what_ob->query("base_unit"),
	what_ob->query("name")), me);

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);

	return 1;
}

int do_withdraw(string arg)
{
	string what,type;
	int amount, money_limit;
	object ob, me;
	int v;

	me = this_player();

	if (me->is_busy())
		return notify_fail("你还是等有空了再说吧！\n");

	if (this_object()->is_fighting())
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if (!me->query("balance")||me->query("balance")<0)
		return notify_fail(ZJOBLONG"你在本店没存款吧？\n");

	if (!arg)
	{
		write(ZJOBLONG"请选择要取出的货币种类：\n"ZJOBACTS2+ZJMENUF(4,4,8,30)"黄金:qu gold"ZJSEP"银票:qu cash"ZJSEP"银两:qu silver"ZJSEP"铜钱:qu coin\n");
		return 1;
	}

	if (sscanf(arg, "%d %s", amount, what) != 2)
	{
		if(arg=="cash")
		{
			if((money_limit=me->query("balance")/100000)<1)
				return notify_fail(ZJOBLONG"你在本店的存款不足一张千两银票，不能支取！\n");
			type = "张千两银票";
		}
		else if(arg=="gold")
		{
			if((money_limit=me->query("balance")/10000)<1)
				return notify_fail(ZJOBLONG"你在本店的存款不足一两黄金，不能取出黄金！\n");
			type = "两黄金";
		}
		else if(arg=="silver")
		{
			if((money_limit=me->query("balance")/100)<1)
				return notify_fail(ZJOBLONG"你在本店的存款不足一两白银，不能支取！\n");
			type = "两白银";
		}
		else if(arg=="coin")
		{
			if((money_limit=me->query("balance"))<1)
				return notify_fail(ZJOBLONG"你在本店的存款不足一枚铜板，不能支取！\n");
			type = "枚铜板";
		}
		write(INPUTTXT("以你目前的存款最多能取出"+money_limit+type+"，你想取出多少"+type+"？","qu $txt# "+ arg)+"\n");
		return 1;
	}

	if (amount < 1)
		return notify_fail("你想取出多少钱？\n");

	if(amount >= 10000)
		return notify_fail("这么大的数目。本店没这么多零散现金。\n");

	if (file_size("/clone/money/" + what + ".c") < 0)
		return notify_fail("你想取出什么钱？\n");

	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance") || v <= 0)
	       return notify_fail("你存的钱不够取。\n");

	ob = new(what);
	ob->set_amount(amount);
	type = ob->short();
	if(ob->move(me))
	{
		me->start_busy(1);
		me->add("balance", -v);
		message_vision(sprintf("$N从银号里取出%s。\n",type), me);
	}
	else
	{
		destruct(ob);
		return notify_fail("取钱失败。\n");
	}
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
