#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	int onlinetime;
	int i,last,times,pot;

	onlinetime = me->query("online_time");


	 if(arg=="-online") 
	{
		if (onlinetime<60*30)
			return notify_fail("你的在线时间不足三十分钟，不能领取在线奖励。\n");
			
		write("你累计在线"+CHINESE_D->chinese_time(me->query("online_time"))+"。\n");
		
		if (onlinetime>60*60*12) 
		onlinetime = 100*100*10;
		
		write("你获得了"+onlinetime+"点经验。\n");
		write("你获得了"+onlinetime/2+"点潜能。\n");
		write("你获得了"+onlinetime+"个铜钱。\n");
		me->add("combat_exp",onlinetime);
		me->add("potential",onlinetime/2);
		me->add("balance",onlinetime);
		me->set("online_time",0);
	}
	
	else
	 if(arg=="-daysign")
	{
	string *list,file;
	mapping gifts;
	object ob;

	gifts = ([
	
		"/clone/shizhe/putao":10,
		"/clone/shizhe/ling_tiaozhan":10,
		"/clone/shizhe/dan_chongmai1":10,
		
	]);

	last = me->query("last_day_sign");
	times = me->query("day_sign_times");
	if(time()/86400 == last/86400)
		return notify_fail("你今天已签过到了，你目前已连续签到【"+HIY+times+NOR+"】天。\n");

	if(times>=6)
	{
		tell_object(me,"你完成了一轮签到。\n");
		me->set("day_sign_times",6);
		times = 6;
	}
	if(time()/86400 - last/86400 > 1)
	{
		tell_object(me,"你昨天没有签到记录，连续记录从今天开始。\n");
		times = 0;
	}

	me->set("last_day_sign",time());
	times += 1;
	me->set("day_sign_times",times);
	pot = random(1000) + 500 + times*100;
	me->add("potential",pot);
	me->add("combat_exp",pot);
	write(BO_D->add_exp(me,10)+"\n");
	tell_object(me,"你连续签到"+HIY+times+NOR+"次，获得"+HIY+pot+NOR+"点经验和潜能。\n");
	list = keys(gifts);
	for(i=0;i<sizeof(list);i++)
	{
		file = list[i];
		if((gifts[file]+times*10) > random(100))
		{
			ob = new(file);
			tell_object(me,"你获得了"+ob->short()+"。\n");
			ob->move(me);
		}
	}
	return 1;
	}

	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: getreward -

这个指令让你获得各种福利。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
