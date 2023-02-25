// quest.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,obj;
	mapping q;
	string master,str,msg;
    msg=ZJOBLONG+"以下是你的师门任务详情："ZJBR;
    msg+="你本周已经完成了师门任务"+HIM+me->query("shimen/today")+NOR+"次，连续任务"+me->query("quest_count")+"次。"ZJBR;
    if (me->query_condition("db_pot2"))
	msg+= HIG"你的玄灵丹[潜能]时间还有"+chinese_number(me->query_condition("db_pot2")/6)+"分钟。"NOR""ZJBR;
    else
    if (me->query_condition("db_pot"))
	msg+=HIG"你的天灵丹[潜能]时间还有"+chinese_number(me->query_condition("db_pot")/6)+"分钟。"NOR""ZJBR;
    
	if (me->query_condition("db_exp2"))
	msg+=HIG"你的玄灵丹[经验]时间还有"+chinese_number(me->query_condition("db_exp2")/6)+"分钟。"NOR""ZJBR;
	else	
	if (me->query_condition("db_exp"))
	msg+=HIG"你的天灵丹[经验]时间还有"+chinese_number(me->query_condition("db_exp")/6)+"分钟。"NOR""ZJBR;
	
if (me->query("shimen/auto") && me->query("quest/id")) {
	if (objectp(present(me->query("quest/id"),environment(me)))) {
		me->force_me("kill " + me->query("quest/id"));
		return 1;
	}
}
	
	while (arg)
	{
		if (arg == "cancel")
		{

	if (mapp(q=me->query("quest"))){
	if(q["place"]==0){	
	write("执行结果： "+me->name()+"\n");
	me->delete("quest");	
	return 1;
	}
  }

			if (! stringp(master = me->query("quest/master_id")))
				return notify_fail("有人向你下任务了吗？\n");
				if (! objectp(ob = present(master, environment(me))))
				return notify_fail("给你下任务的那个人现在不在这里吧？\n");
	
		}
		else  if (! objectp(ob = present(arg, environment(me))))
			return notify_fail("这里没有这个人，你怎么领任务？\n");

		if (! living(ob))
			return notify_fail("你还是等" + ob->name() + "醒了再说吧！\n");

		if (me->is_fighting())
			return notify_fail("专心打你的架！\n");

		if (me->is_busy())
			return notify_fail("你还是有空了再和" + ob->name() + "谈这些问题吧！\n");

		if (ob->is_fighting())
			return notify_fail("你还是等" + ob->name() + "打完架再说吧！\n");

		if (ob->is_busy())
			return notify_fail(ob->name() + "正忙着呢，没功夫理你。\n");

		notify_fail(ob->name() + "望着你呵呵的傻笑。\n");
		
		return (arg == "cancel" ? ob->cancel_quest(me) : ob->ask_quest(me));
	}
 
	if (! mapp(q =  me->query("quest"))){
		msg+=HIY"你现在没有领任何任务！"NOR"\n";
		msg+=ZJOBACTS2+ZJMENUF(2,2,9,31);
		msg+="返回师门:recalle"ZJSEP;
		msg+="自动师门:zdsm";
		write(msg+"\n");
		return 1;
	}
	if(objectp(obj=find_living(""+q["id"]+""))&&environment(obj))
	str = "据说此人目前在" + q["place"] + environment(obj)->query("short") + "出没。\n";
	else
	str = "此人已消失！\n";	
	switch (q["type"])
	{
	case "kill":
		msg+=q["master_name"] + "吩咐你在" + CHINESE_D->chinese_monthday(q["limit"]) + "之前割下" HIY +q["name"] + NOR "(" + q["id"] + ")的人头，回" + q["family"] + "交差。"ZJBR"" + "据说此人前不久曾经在" + q["place"] + "出没。\n";
		msg+=ZJOBACTS2+ZJMENUF(2,2,9,31);
		msg+="返回师门:recalle"ZJSEP;
		msg+="自动师门:zdsm";
		write(msg+"\n");
		return 1;
	case "letter":
		msg+=q["master_name"] + "吩咐你在" + CHINESE_D->chinese_monthday(q["limit"]) + "之前把信件送到" HIC + q["name"] + NOR "(" + q["id"] + ")手中，取回执交差。\n";		
		msg+=ZJOBACTS2+ZJMENUF(2,2,9,31);
		msg+="返回师门:recalle"ZJSEP;
		msg+="自动师门:zdsm";
		write(msg+"\n");
		return 1;
	}
	msg+="你现在没有领任何任务！\n";
	msg+=ZJOBACTS2+ZJMENUF(2,2,9,31);
	msg+="返回师门:recalle"ZJSEP;
	msg+="自动师门:zdsm";
	write(msg+"\n");
	return 1;
	

}

int help(object me)
{
	write(@HELP
指令格式 : quest  这个指令可以用来向你的门派的掌门或世家长辈
领取任务，如果不加任何参数则显示出你当前的任务。
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
