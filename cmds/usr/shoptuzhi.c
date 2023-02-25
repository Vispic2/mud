#include <ansi.h>

#define shoptuzhi_DIR	"/clone/tattoo/"

inherit F_CLEAN_UP;

mapping mtypes = ([
	"宝石类":"baoshi",
	"属性类":"attrib",
	"装备类":"weapon",
	"技能类":"skill",
	"丹药类":"medicine",
	"任务类":"job",
	"特殊类":"special",
	"限时特价":"jieri",
]);

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int fix,i,tuzhi,value;
	object ob;
	mixed today;
	int jieri,amount;

	all_file = list_dirs(shoptuzhi_DIR);

	if(!sizeof(all_file))
		return notify_fail("商城中赞助商品出售。\n");

	today = localtime(time());
	if((today[4]+1)==1 && today[3]>=1 && today[3]<=3)
		fix = 80;
	else fix = 100;

	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("tuzhi")+"图纸残片，请选择您想购买的道具：\n"ZJOBACTS2+ZJMENUF(1,1,8,30);
		today = localtime(time());
		
		//str += "限时特价:shoptuzhi type 限时特价"ZJSEP;
		//str += "特殊道具:shoptuzhi type 特殊类"ZJSEP;
	//	str += "宝石商店:shoptuzhi type 宝石类"ZJSEP;
	//	str += "技能商店:shoptuzhi type 技能类"ZJSEP;
	//	str += "丹药商店:shoptuzhi type 丹药类"ZJSEP;
	//	str += "装备材料:shoptuzhi type 装备类"ZJSEP;
		for(i=0;i<sizeof(all_file);i++)
		{
			file = shoptuzhi_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			tuzhi = file->query("tuzhi");
			if(tuzhi)
			{
				tuzhi = tuzhi*fix/100;
				if(tuzhi<1) tuzhi = 1;
			}
			price = tuzhi?(tuzhi+"图纸残片"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:shoptuzhi look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if(arg=="type")
	{
		str = ZJOBLONG"你目前有"+me->query("tuzhi")+"图纸残片，请选择您想购买的道具类别：\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		types = sort_array(keys(mtypes),(:strcmp:));
		for(i=0;i<sizeof(types);i++)
		{
			str += sprintf("%s:shoptuzhi type %s"ZJSEP,types[i],types[i]);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"type %s",type)==1)
	{
		if(!mtypes[type])
			return notify_fail("商城中赞助"HIG+type+NOR"类商品出售。\n");
		all_file = list_dirs(shoptuzhi_DIR+mtypes[type]+"/");
		if(!sizeof(all_file))
			return notify_fail("商城中赞助"HIG+type+NOR"类商品出售。\n");
		if(type == "限时特价")
			str = ZJOBLONG"你目前有"+me->query("tuzhi")+"图纸残片，请选择您想购买的"HIG+type+NOR"类道具："ZJBR HIR"注意：本类道具为绑定道具！"NOR"\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		else
			str = ZJOBLONG"你目前有"+me->query("tuzhi")+"图纸残片，请选择您想购买的"HIG+type+NOR"类道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = shoptuzhi_DIR+mtypes[type]+"/"+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			tuzhi = file->query("tuzhi");
			price = tuzhi?(tuzhi+"图纸残片"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:shoptuzhi look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		tuzhi = file->query("tuzhi");
			if(tuzhi)
			{
				tuzhi = tuzhi*fix/100;
				if(tuzhi<1) tuzhi = 1;
			}
		price = tuzhi?(tuzhi+"图纸残片"):(MONEY_D->money_str(file->query("value")));
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "购买1个:shoptuzhi buy 1 "+file+ZJSEP"批量购买:shoptuzhi buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,shoptuzhi_DIR)!=0)
				return notify_fail(HIM"没有这个道具！！"NOR"\n");

			write(INPUTTXT("你想买多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","shoptuzhi buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,shoptuzhi_DIR)!=0)
			return notify_fail(HIM"没有这个道具！！"NOR"\n");

		if(file->query("no_shop"))
			return notify_fail(HIM"已下架商品，无法购买！！"NOR"\n");
		if(file->query("jieri")&&!jieri)
			return notify_fail(HIM"特殊节日商品，非开放时间无法购买！！"NOR"\n");
		if(amount<1)
			return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(amount>999)
			return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(!file->query_amount()&&amount>10)
			return notify_fail(HIM"不可叠加物品一次最多买10个！！"NOR"\n");

		if(file->query("max_buy"))
		{
			if(me->query("buy_max/"+file->query("id"))+amount>file->query("max_buy"))
				return notify_fail(HIM"限量购买道具，你还能购买"+(file->query("max_buy")-me->query("buy_max/"+file->query("id")))+"个！！"NOR"\n");
		}
		tuzhi = file->query("tuzhi");
			if(tuzhi)
			{
				tuzhi = tuzhi*fix/100;
				if(tuzhi<1) tuzhi = 1;
			}
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!tuzhi&&!value)
			return notify_fail(HIM"购买失败！！"NOR"\n");

		if(tuzhi)
		{
			if(!me->query("tuzhi")||me->query("tuzhi")<(tuzhi*amount))
				return notify_fail(HIM"你的图纸残片不足，可以击杀幽魂获得！！"NOR"\n");
			me->add("tuzhi",-tuzhi*amount);
			log_file("cmds/shoptuzhi", sprintf("%s:%s(%s)消费%d图纸残片，从青阳子购买%d个%s(%s)。\n",
				ctime(time()),me->query("name"),me->query("id"),tuzhi*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/tuzhi_used",tuzhi*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"你的图纸残片没那么多了！！"NOR"\n");
			log_file("cmds/shoptuzhis", sprintf("%s:%s(%s)消费%s，从青阳子购买%d个%s。\n",
				ctime(time()),me->query("name"),me->query("id"),MONEY_D->money_str(value*amount),amount,file->query("name")));
		}
		if(file->query_amount())
		{
			ob = new(file);
			ob->set_amount(amount);
			write("你从商城中成功购买到"+ob->short()+"。"NOR"\n");
			ob->move(me,1);
		}
		else
		{
			for(i=0;i<amount;i++)
			{
				ob = new(file);
				ob->move(me,1);
			}
			write("你从商城中成功购买到"+amount+ob->query("unit")+ob->short()+"。"NOR"\n");
		}
		if(file->query("max_buy"))
		{
			me->add("buy_max/"+file->query("id"),amount);
		}
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

int help(object me)
{
     write(@HELP

青阳子。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
