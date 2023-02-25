#include <ansi.h>

#define myshop1_DIR	"/clone/vip1/"

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
	int fix,i,yuanbaos,value;
	object ob;
	mixed today;
	int jieri,amount;

	all_file = list_dirs(myshop1_DIR);

	if(!sizeof(all_file))
		return notify_fail("商城中赞助商品出售。\n");

	today = localtime(time());
	if((today[4]+1)==1 && today[3]>=1 && today[3]<=3)
		fix = 80;
	else fix = 100;

	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("yuanbaos")+"元宝票，请选择您想购买的道具"HIR"注意:(元宝票商城购买道具均为绑定物品)"NOR"：\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		today = localtime(time());
		
		//str += "限时特价:myshop1 type 限时特价"ZJSEP;
		//str += "特殊道具:myshop1 type 特殊类"ZJSEP;
	//	str += "宝石商店:myshop1 type 宝石类"ZJSEP;
	//	str += "技能商店:myshop1 type 技能类"ZJSEP;
	//	str += "丹药商店:myshop1 type 丹药类"ZJSEP;
	//	str += "装备材料:myshop1 type 装备类"ZJSEP;
		for(i=0;i<sizeof(all_file);i++)
		{
			file = myshop1_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuanbaos = file->query("yuanbaos");
			if(yuanbaos)
			{
				yuanbaos = yuanbaos*fix/100;
				if(yuanbaos<1) yuanbaos = 1;
			}
			price = yuanbaos?(yuanbaos+"元宝票"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshop1 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if(arg=="type")
	{
		str = ZJOBLONG"你目前有"+me->query("yuanbaos")+"元宝票，请选择您想购买的道具类别，"HIR"注意:(元宝票商城购买道具均为绑定物品)"NOR"：\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		types = sort_array(keys(mtypes),(:strcmp:));
		for(i=0;i<sizeof(types);i++)
		{
			str += sprintf("%s:myshop1 type %s"ZJSEP,types[i],types[i]);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"type %s",type)==1)
	{
		if(!mtypes[type])
			return notify_fail("商城中赞助"HIG+type+NOR"类商品出售。\n");
		all_file = list_dirs(myshop1_DIR+mtypes[type]+"/");
		if(!sizeof(all_file))
			return notify_fail("商城中赞助"HIG+type+NOR"类商品出售。\n");
		if(type == "限时特价")
			str = ZJOBLONG"你目前有"+me->query("yuanbaos")+"元宝票，请选择您想购买的"HIG+type+NOR"类道具："ZJBR HIR"注意：本类道具为绑定道具！"NOR"\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		else
			str = ZJOBLONG"你目前有"+me->query("yuanbaos")+"元宝票，请选择您想购买的"HIG+type+NOR"类道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,35);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = myshop1_DIR+mtypes[type]+"/"+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuanbaos = file->query("yuanbaos");
			price = yuanbaos?(yuanbaos+"元宝票"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshop1 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		yuanbaos = file->query("yuanbaos");
			if(yuanbaos)
			{
				yuanbaos = yuanbaos*fix/100;
				if(yuanbaos<1) yuanbaos = 1;
			}
		price = yuanbaos?(yuanbaos+"元宝票"):(MONEY_D->money_str(file->query("value")));
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "购买1个:myshop1 buy 1 "+file+ZJSEP"批量购买:myshop1 buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,myshop1_DIR)!=0)
				return notify_fail(HIM"没有这个道具！！"NOR"\n");

			write(INPUTTXT("你想买多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","myshop1 buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,myshop1_DIR)!=0)
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
		yuanbaos = file->query("yuanbaos");
			if(yuanbaos)
			{
				yuanbaos = yuanbaos*fix/100;
				if(yuanbaos<1) yuanbaos = 1;
			}
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!yuanbaos&&!value)
			return notify_fail(HIM"购买失败！！"NOR"\n");

		if(yuanbaos)
		{
			if(!me->query("yuanbaos")||me->query("yuanbaos")<(yuanbaos*amount))
				return notify_fail(HIM"你的元宝票不足，请赞助！！"NOR"\n");
			me->add("yuanbaos",-yuanbaos*amount);
			log_file("cmds/myshop1", sprintf("%s:%s(%s)消费%d元宝票，从随身商城购买%d个%s(%s)。\n",
				ctime(time()),me->query("name"),me->query("id"),yuanbaos*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/yuanbaos_used",yuanbaos*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"你的钱没那么多了！！"NOR"\n");
			log_file("cmds/myshops1", sprintf("%s:%s(%s)消费%s，从随身商城购买%d个%s。\n",
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

随身商城。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
