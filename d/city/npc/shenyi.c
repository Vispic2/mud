inherit NPC;
#include <localtime.h>

string ask_zhengrong();

void create()
{
	set_name("妙手神医", ({"shenyi"}));
	set("long", "他好像一脸猥琐的盯着你！");
	set("combat_exp", 10000);
	
	set("inquiry", ([
		"【整容】" : (: ask_zhengrong :),
		]));
	setup();
}

void init()
{
	add_action("do_zhengrong", "zhengrong");
}

string ask_zhengrong()
{
	this_player()->force_me("zhengrong");
	return "";
}
int do_zhengrong(string arg)
{
	object who = this_player();
	int last_time, num;
	
	
	last_time = who->query("shenyi_zhengrong");
	if ((localtime(last_time)[LT_MON] == localtime(time())[LT_MON]) && (localtime(last_time)[LT_MDAY] == localtime(time())[LT_MDAY]))
	{
		write(ZJOBLONG + "一天只能整容一次。\n");
		return 1;
	}
	
	if (!arg)
	{
		write(INPUTTXT("一天一次，需要花费100金。"ZJBR"你想将容貌修改为多少？(10-30)", "zhengrong $txt#") + "\n");
		return 1;
	}
	
	if (!sscanf(arg, "%d", num) || num < 10 || num > 30)
	{
		write(ZJOBLONG + "请输入一个大于10，小于30的数。\n");
		return 1;
	}
	
	if (!MONEY_D->player_pay(who, 1000000))
		return notify_fail(ZJOBLONG + "你的钱不够。\n");
	
	who->set("per", num);
	who->set("shenyi_zhengrong", time());
	write("整容成功，你的容貌修改为" + num + "。\n");
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
