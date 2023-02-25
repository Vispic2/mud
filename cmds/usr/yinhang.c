//cpasswd.c by XiaoYao
// Modify by snowman@SJ 01/05/1999.
#include <ansi.h>
inherit F_CLEAN_UP;
//int help(object me);
int main(object me, string arg)
{
object who = this_player();
	string type;
	int num;
	
    	if (!arg)
	
	{
	
	
		write(ZJOBLONG + "你要使用什么服务？\n" + ZJOBACTS2+ZJMENUF(3,3,8,30) + "存潜能:yinhang cun"ZJSEP"取潜能:yinhang qu"ZJSEP"查询:yinhang check\n");
		return 1;
	}
	
	if (arg == "cun")
	{
		write(INPUTTXT("你目前有" + ((int)who->query("potential") - (int)who->query("learned_points")) + "潜能，你要存入多少潜能？", "yinhang cun $txt#") + "\n");
		return 1;
	}
	
	if (arg == "qu")
	{
		write(INPUTTXT("你目前存有" + who->query("yinhang/amount") + "潜能，你要取出多少潜能？", "yinhang qu $txt#") + "\n");
		return 1;
	}
	
	if (arg == "check")
	{
		write(ZJOBLONG + "你目前存在潜能银行的潜能为" + who->query("yinhang/amount") + "。\n");
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
			who->add("yinhang/amount", num);
			who->add("potential", -num);
			write(ZJOBLONG + "你存入了" + num + "潜能，花费10两白银。\n");
			return 1;
		}
		else if (type == "qu" && num > 0)
		{
			if (who->query("yinhang/amount") < num)
				return notify_fail(ZJOBLONG + "你存在潜能银行的潜能没那么多了。\n");
			if (!MONEY_D->player_pay(who, 1000))
				return notify_fail(ZJOBLONG + "你银子不足。\n");
			who->add("yinhang/amount", -num);
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
	return 1;
	}
	
	/*"else


	if (arg=="shi")
	{
	{
		write(ZJOBLONG + "你要使用什么服务？\n" + ZJOBACTS2+ZJMENUF(3,3,8,30) + "存实战:yinhangs cun"ZJSEP"取实战:yinhangs qu"ZJSEP"查询:yinhangs check\n");
		return 1;
	}
	
	if (arg == "cuns")
	{
		write(INPUTTXT("你目前有" + ((int)who->query("experience"))+ "实战，你要存入多少实战？", "yinhangs cun $txt#") + "\n");
		return 1;
	}
	
	if (arg == "qus")
	{
		write(INPUTTXT("你目前存有" + who->query("yinhangs/amount") + "实战，你要取出多少实战？", "yinhangs qu $txt#") + "\n");
		return 1;
	}
	
	if (arg == "checks")
	{
		write(ZJOBLONG + "你目前存在实战银行的实战为" + who->query("yinhangs/amount") + "。\n");
		return 1;
	}
	
	if (sscanf(arg, "%s %d", type, num) == 2)
	{
		if (type == "cun" && num > 0)
		{
			if (((int)who->query("experience")) < num)
				//if (((int)who->query("experience") - (int)who->query("learned_points")) < num)
				return notify_fail(ZJOBLONG + "你的实战没那么多了。\n");
			if (!MONEY_D->player_pay(who, 1000))
				return notify_fail(ZJOBLONG + "你银子不足。\n");
			who->add("yinhangs/amount", num);
			who->add("experience", -num);
			write(ZJOBLONG + "你存入了" + num + "实战，花费10两白银。\n");
			return 1;
		}
		else if (type == "qu" && num > 0)
		{
			if (who->query("yinhangs/amount") < num)
				return notify_fail(ZJOBLONG + "你存在实战银行的实战没那么多了。\n");
			if (!MONEY_D->player_pay(who, 1000))
				return notify_fail(ZJOBLONG + "你银子不足。\n");
			who->add("yinhangs/amount", -num);
			who->add("experience", num);
			write(ZJOBLONG + "你取出了" + num + "实战，花费10两白银。\n");
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
	return 1;
	}
	}
	*/
    

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
