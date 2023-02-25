inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", @LONG
这里是城市的正中心，一个很宽阔的广场。中央有一棵大榕树，据传已有千年的树龄，是这座城市的历史见证。树干底部有一个很大
的树洞。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "city");
	set("item_desc", ([
		"【树洞】" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n"
		ZJOBACTS2"钻洞:enter dong\n",
			"武林楷模" : "这上面的便是站在武林之巅的圣人！\n"
		ZJOBACTS2"武林楷模:lunsword\n",
	
			"悬赏栏" : "这是悬赏公告栏，你可以在这里查看悬赏信息。\n"
					"可以花金子悬赏玩家，包括自己。\n" 
					"只有在线的玩家才可以被悬赏。\n" + 
					ZJOBACTS2 + "悬赏信息:look_board" + ZJSEP + "悬赏玩家:xuanshang\n",
	]));

	set("action_list", ([
		HIY"开服助力"NOR : "kaifu_zhuli",
	]));

	set("exits", ([
		"northeast" : __DIR__"shengxiantang",
		"northwest" : __DIR__"banghui",
		"southeast" : __DIR__"heishi",
		"southwest" : __DIR__"lajichang",
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
"up" : __DIR__"shiji"
	]));

	set("objects", ([
		__DIR__"npc/liapo" : 1,
		"/adm/npc/tiaoz" :1, 

	     
	]));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_kaifu", "kaifu_zhuli");
     add_action("do_xuanshang", "xuanshang");
	add_action("do_look_board", "look_board");
	add_action("do_jiebang", "jiebang");
}

#define XUANSHANGD "/adm/daemons/xuanshangd"
#define ORDER "/clone/xuanshang/xuanshang_order"

int do_xuanshang(string arg)
{
	object who = this_player();
	object target;
	int amount;

	if (arg == "" || !arg)
	{
		tell_object(who, INPUTTXT("你要悬赏谁？(输入ID)", "xuanshang $txt#") + "\n");
		return 1;
	}

	if (sscanf(arg, "%s %d", arg, amount) != 2)
	{
		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "这个人目前不在江湖之中。\n");
			return 1;
		}
		else
		{
			tell_object(who, INPUTTXT("你目前有" + (who->query("balance") / 10000) + "两黄金存款，你要悬赏" + target->query("name") + "多少金子?", "xuanshang " + arg + " $txt#") + "\n");
			return 1;
		}
	}
	else
	{
		if (amount <= 0)
		{
			tell_object(who, "请输入大于零的数。\n");
			return 1;
		}

		if (who->query("balance") < amount * 10000)
		{
			tell_object(who, "你的存款不足" + amount + "两黄金。\n");
			return 1;
		}

		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "这个人目前不在江湖之中。\n");
			return 1;
		}
		else
		{
			who->add("balance", -amount * 10000);
			if (XUANSHANGD->add_xuanshang(target->query("id"), amount))
			{
				log_file("d/xuanshang", ctime(time()) + who->query("name") + "(" + who->query("id") + ")花费" + amount + "金子悬赏" + target->query("name") + 
					"(" + target->query("id") + ")，目前总计" + XUANSHANGD->get_xuanshang()[target->query("id")][1] + "黄金。\n");
				tell_object(who, "你花费" + amount + "金子悬赏" + target->query("name") + "。\n");
				return 1;
			}
			else
			{
				tell_object(who, "悬赏出错，请联系管理员处理。\n");
				return 1;
			}

			return 1;
		}
	}

	return 1;
}

int do_look_board(string arg)
{
	object who = this_player();
	string temp;
	string str = "";
	mapping xuanshang;

	if (!sizeof(xuanshang = XUANSHANGD->get_xuanshang()))
	{
		tell_object(who, "目前江湖中没有被悬赏的人。\n");
		return 1;
	}

	foreach (temp in keys(xuanshang))
	{
		str += xuanshang[temp][0] + "(" + xuanshang[temp][1] + ")" + ":jiebang " + temp + ZJSEP;
	}

	if (str == "")
		tell_object(who, ZJOBLONG + "目前江湖中没有被悬赏的人。\n");
	else
		tell_object(who, ZJOBLONG + "目前江湖中被悬赏的人有：\n" + ZJOBACTS2 + str + "\n");

	return 1;
}

int do_jiebang(string arg)
{
	object who = this_player();

	string id;
	string sign;
	object order;
	mapping xuanshang;

	xuanshang = XUANSHANGD->get_xuanshang();
	
	if (sscanf(arg, "%s %s", id, sign) != 2)
	{
		if (undefinedp(xuanshang[arg]))
		{
			tell_object("目前没有这个悬赏令啊。\n");
			return 1;
		}

		tell_object(who, ZJOBLONG + "你要揭下" + xuanshang[arg][0] + "的悬赏令吗？\n" + ZJOBACTS2 + "确定:jiebang " + arg + " y\n");
		return 1;
	}
	else
	{
		if (sign != "y")
		{
			tell_object(who, "输入参数错误，请重新输入。\n");
			return 1;
		}

		if (undefinedp(xuanshang[id]))
		{
			tell_object("目前没有这个悬赏令啊。\n");
			return 1;
		}

		if (present(id + "-order", who))
		{
			tell_object(who, "你的身上已经有这个悬赏令了。\n");
			return 1;
		}

		if (!objectp(order = new(ORDER)))
		{
			tell_object(who, "出错，请联系管理员处理。\n");
			return 1;
		}

		order->set("xuanshang_id", id);
		order->set("xuanshang_name", xuanshang[id][0]);
		order->set_name(xuanshang[id][0] + "悬赏令", ({ id + "-order" }));
		order->move(who);
		tell_object(who, "你揭下了" + xuanshang[id][0] + "的悬赏令。\n");

		return 1;
	}
}

int do_kaifu(string arg)
{
	string str;
	object ob,me,box;
	int last,exp,pot;

	me = this_player();

	if(!arg)
	{
		str = ZJOBLONG"欢迎各位玩家对巫师的支持！本服刚开有能力的朋友希望可以去拉些朋友一起玩！\n";
		str += ZJOBACTS2"助力:kaifu_zhuli ok\n",
		write(str);
		return 1;
	}

	last = me->query("zjvip/last_shake_shu");
	if(localtime(time())[3] == localtime(last)[3])
	return notify_fail(HIR"你今天已经助力了，明天再来吧！\n"NOR);
	me->set("zjvip/last_shake_shu",time());
	exp=10000+random(5000);
	me->add("combat_exp",exp);
	tell_object(me,"你得到了"+exp+"点经验！\n");
	pot=10000+random(5000);
	me->add("potential",pot);
	tell_object(me,"你得到了"+pot+"点经验！\n");
	return 1;
}


int do_enter(string arg)
{
	object me;
	me = this_player();

	if (! arg || arg == "")
		return 0;

	if (arg == "dong")
	{
		if (me->is_busy())
			return notify_fail("你的动作还没有完成，不能移动。\n");

		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
		me->move("/d/gaibang/inhole");
		message("vision",
			me->name() + "从洞里走了进来。\n",
			environment(me), ({me}) );
		return 1;
	}
}       

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
