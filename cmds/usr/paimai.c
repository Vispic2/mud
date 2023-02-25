// cmds/std/auction.c 拍卖与竞价程序
// call_out() 映射控制版 for sz	xo2(xkx)
/*
key  string ob_id      物品ID
v[0] object obj	       拍卖物品	    
v[1] int    ob_price   竞标价格		      
v[2] object ob_auction 竞标者		      
v[3] object ob_onwer   物品所有者	      
v[4] string ob_desc    物品所有者对该物品的介绍
v[5] string auction_id 竞标者ID
v[6] string onwer_id   物主ID
v[7] string ob_name    物品名称
v[8] string ob_long    物品描述

mapping	structure:
auction[obj : {ob, ob_price, ob_auction, ob_onwer, ob_desc, auction_id,	...} ]
*/

#include <ansi.h>
inherit	F_DBASE;

#define	PRICE_DIFFERENCE 100

mapping auction = ([]);

// 状态变化的控制中心
void auction_chat(string msg);	
void auction_state_check(int times, int	s_times, int last_price, string	obj_id); 
// 静止的状态切换
void auction_end(string	ob_name, int ob_price, mixed ob_auction, object	ob_onwer, object ob, string ob_id);
void auction_cancel(string ob_id, object discredit_1, object discredit_2);
// 实现拍卖
void get_ob_desc(string	desc, object me, string	str, int num);
void choise_secret(string decide, object me, string ob_id, string desc,	int num);
// 数据反馈
int player_demand(int num, string unit,	object me, string flag);
int player_bank(object ob);
int player_pay(object who, int amount);
int help();
int help_2();

// channeld.c需要增加auction频道
int clean_up(){	return 1;}

void create()
{
	seteuid(ROOT_UID);
	set("name", "拍卖指令");
	set("id", "jiaoyi");
	set("channel_id","");
}

void auction_chat(string msg) 
{	
	msg = replace_string(msg, NOR, HIY);	
	CHANNEL_D->do_channel(this_object(),"jiaoyi",msg);
}

void auction_state_check(int times, int	s_times, int last_price, string	obj_id)
{
	int    i, ob_price, flag1 = 0, flag2 = 0;
	object ob, ob_auction, ob_onwer, new_auction, new_onwer, nul;
	mixed  *v;
	string *k, ob_name, ob_id, str;
	
	// 重新定位此物品，避免因为其他物品被清除导致索引号变化
	k = keys(auction);
	i = member_array(obj_id,k); 
	v = values(auction)[i];
	ob_id	   = k[i];
	ob	   = v[0];
	ob_price   = v[1];
	ob_auction = v[2];
	ob_onwer   = v[3];
	ob_name	   = v[7];
	
	if(!objectp(ob_auction)	&& !stringp(ob_auction))
	{
		flag1++;
		if(objectp(new_auction = find_player(v[5])))
		{
			ob_auction = new_auction;
			flag1 =	0;
		}
	}
	if(!objectp(ob_onwer))
	{
		flag2++;
		if(objectp(new_onwer = find_player(v[6])))
		{
			ob_onwer = new_onwer;
			flag2 =	0;
		}
	}

	if(flag2 && !flag1) 
	{
		str="由于卖方缺席，取消"+ob_name+"的拍卖";
		auction_chat(str);
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	if(!objectp(ob)	|| !objectp(present(ob,ob_onwer)))
	{
		str="由于卖方保管不当，拍卖物品"+ob_name+"丢失，本次拍卖取消！\n";
		auction_chat(str);
		ob_onwer->delete_temp("auctioning");
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	if(times < 120)
	{
		times++;
		if(ob_price > last_price)
		{
			s_times	= 0;
			call_out("auction_state_check",	20, times, s_times, ob_price, ob_id);
		}
		else
		{
			s_times++;
			if(s_times<4)
			{
				str = HIR"第"+CHINESE_D->chinese_number(s_times)+"次喊价:"HIY"拍卖"+ob_name+"，现价"+MONEY_D->price_str(ob_price)+"!!";
				auction_chat(str);   
				call_out("auction_state_check",	30, times, s_times, ob_price, ob_id);
			}
			else
			{
				if(flag1 && !flag2)
				{
					str="由于买方缺席，取消"+ob_name+"的拍卖！";
					auction_chat(str);
					auction_cancel(ob_id, ob_onwer,	nul);
					return;
				}
				if(flag1 && flag2)
				{
					str="由于买卖双方缺席，取消"+ob_name+"的拍卖！";
					auction_chat(str);
					auction_cancel(ob_id, nul, nul);
					return;
				}	
				auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
			}
		}
	}
	else
	{
		if(flag1 && !flag2)
		{
			str="由于买方缺席，取消"+ob_name+"的拍卖！";
			auction_chat(str);
			auction_cancel(ob_id, ob_onwer,	nul);
			return;
		}
		if(flag1 && flag2)
		{
			str="由于买卖双方缺席，取消"+ob_name+"的拍卖！";
			auction_chat(str);
			auction_cancel(ob_id, nul, nul);
			return;
		}
		str = "时间已到，拍卖"+ob_name+"的过程到此为止！\n";
		auction_chat(str);
		auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
		return;
	}
	return ;
}

void auction_end(string	ob_name, int ob_price, mixed ob_auction, object	ob_onwer, object ob, string ob_id)
{

	object	*inv, *en_inv, nul;
	string onwer_id, str;

	if(!objectp(ob_onwer))	return;	 // 虽然不太可能发生，但还是判断下保险
	onwer_id = ob_onwer->query_temp("auction/"+ob_id);
	
	if(stringp(ob_auction))
	{
		str=onwer_id+"以底价"+MONEY_D->price_str(ob_price)+"拍卖"+
		ob_name+"，由于无人投标，本次拍卖无效！\n";		
		auction_cancel(ob_id, ob_onwer,	nul);
		tell_object(ob_onwer,HIR"很遗憾！，"NOR"你的"+ob_name+"无人投标，本次拍卖无效！\n");
		ob_onwer->set("auction_fail",ob_onwer->query("mud_age"));
	}
	else
	{
		str=ob_auction->query("name")+"("+ob_auction->query("id")+")"+"出价"+MONEY_D->price_str(ob_price)+"竞标"+
		ob_name+"成功，本次拍卖成交！\n";
			
		// 买卖双方金钱物品的交换，买方需交成交价10%的中介费
		if(!player_pay(ob_auction, (int)(ob_price*11/10))) 
		{
			str="由于买方无力支付竞价，取消"+ob_name+"的拍卖！\n";
			ob_auction->delete_temp("auctioning");
			auction_cancel(ob_id, ob_onwer,	nul);
		}
		else
		{
			inv = all_inventory(ob_auction); 
			en_inv = all_inventory(environment(ob_auction)); 
			tell_object(ob_auction,"恭喜！你竞标成功，得到了"+ob_name+"\n所需款额包含10%的中介费已经交付讫。\n");
			
			if(!ob->move(ob_auction) || (inv && sizeof(inv)	> 49))
			{
				if(en_inv && sizeof(en_inv) < 49)
				{
					tell_object(ob_auction,	"你手头已经拿不下了,东西落到了你的脚边..\n");
					ob->move(environment(ob_auction)); 
				}
				else
				{
					tell_object(ob_auction,	"此次拍卖所得由于你无力保管而收归国有！\n");
					destruct(ob);
				}
			}	
			tell_object(ob_onwer,ob_name+"拍卖成功！所得款已经自动转至你的钱庄帐户。\n");
			ob_onwer->add("balance",ob_price);
			auction_cancel(ob_id, ob_auction, ob_onwer);
		}
	}
	auction_chat(str);
	return;
}

void auction_cancel(string ob_id, object discredit_1, object discredit_2)
{
	if(member_array(ob_id, keys(auction)) != -1)
		map_delete(auction, ob_id);

	if(objectp(discredit_1))
		discredit_1->delete("discredit/"+ob_id);
	if(objectp(discredit_2))
		discredit_2->delete("discredit/"+ob_id);
}

int main(object	me,string arg)
{
	int i, j, k, coin, guaranty, num, index, cheat_times, ob_price,value, *check_v;
	mixed *ob_value, *v, *v2;
	string str, unit, *tuned_ch, *ob_key, ob_id, *check_k;
	object ob, obj;
	mapping check;
	
	ob_key = keys(auction);
	ob_value = values(auction);
	check = me->query("discredit");
	cheat_times = sizeof(check);
/*

if(!this_player()->query("canpaimai"))
{
    write("sorry, currently disable by scatter\n");
    return 1;
}
*/
	
	if(!arg)
	{
		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch)	)
			me->set("channels", ({ "jiaoyi" }) );
		else if( member_array("jiaoyi", tuned_ch) == -1 )
			me->set("channels", tuned_ch + ({ "jiaoyi" }) );
		tell_object(me,"\n你的交易频道(jiaoyi)现在处于开通状态\n");
		return 1;
	}	
		
	if(arg == "-l")
	{
		if(!sizeof(auction))
		{
			tell_object(me,"目前没有物品被拍卖。\n");
			return 1;
		}
		str=HIG"当前拍卖物品清单：\n\n";
		str += sprintf(HIC"≡"HIY"────────────────────────────────"HIC"≡"NOR"\n");
		str += "  物品名称		   当前标价		 最高竞价者\n";
		str += HIG" ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※ "NOR"\n";
		
		for(i=0; i<sizeof(auction);i++)
		{
			v = ob_value[i];

			str += sprintf("  %-25s  ", v[7]);
			str += sprintf("%-25s  ", MONEY_D->price_str(v[1]));
			str += sprintf("%-10s  \n", (!stringp(v[2]))? v[5] : "");
		}
		str += "\n\n";
		str += sprintf(HIC"≡"HIY"────────────────────────────────"HIC"≡"NOR"\n");
		me->start_more(str);
		return 1;
	}
	if(arg == "-i")
	{
		if(!sizeof(auction))
		{
			tell_object(me,"目前没有物品被拍卖。\n");
			return 1;
		}
		str=HIG"当前拍卖物品详细介绍：\n"NOR"\n";
		for(i=0; i<sizeof(auction);i++)
		{
			v = ob_value[i];

			str+=HIG"------------"NOR"\n物品名称： "+v[7]+
			"\n物品描述："+v[8]+
			"\n物主介绍："+v[4]+
			"\n物主："+v[6]+"\n\n";
		}
		me->start_more(str);		
		return 1;
	}
	if(arg == "-h")
		return help_2();
	if(sscanf(arg,"%s for %d %s",str,num,unit) == 3)
	{
		
		str = lower_case(str);
		if(me->query("age") < 18)
		{
			tell_object(me,"你还没有成年，能对自己的拍卖行为负责吗？\n");
			return 1;
		}			
		if(me->query("combat_exp") < 3000000)
		{
			tell_object(me,"你虽已成年，但是涉世经验太少，无法对自己的拍卖行为负责。【需要300w经验】\n");
			return 1;
		}


				if(unit != "gold" && unit !="silver")
				{
					write("现在只接受以黄金(gold)和白银（silver)交易\n");
					return 1;
				}

				if( num < 0 )
				{
					write("请不要做违法事情\n");
					return 1;
				}

				if( num > 500 )
				{
					write("不能超过五百两黄金\n");
					return 1;
				}



		if(cheat_times && !me->query_temp("auctioning"))
		{
			check_v = values(check);
			check_k = keys(check);
			for(j = 0; j < sizeof(check_v); j++)
			{
				if(me->query("mud_age") - check_v[j] < 3600*cheat_times)	
				{
					tell_object(me,"你由于在某次拍卖过程中信誉值降低，暂时无权参与。\n");
					return 1;
				}
				else map_delete(check, check_k[j]);			
			}
		}
		if(me->query("mud_age")	- me->query("auction_fail") < 60)
		{
			tell_object(me,"你上次拍卖的物品无人问津，这回还是先花点时间调查市场吧。\n");
			return 1;		
		}
		if(sizeof(auction) > 4) // 决定同时间内有多少拍卖进程可以并存
		{
			tell_object(me,"拍卖物品队列已满，请少候。\n");
			return 1;
		}
		if(!objectp(ob = present(str,me)))
		{
			tell_object(me,"你身上没有 "+HIG+str+NOR+" 这件物品。\n");
			return 1;
		}
		ob_id = ob->query("id");		
		if(member_array(ob_id, ob_key)!= -1)
		{
			tell_object(me,"你晚了一步，这类物品已经有人拍卖了。\n");
			return 1;
		}
		
		if( ob->query("money_id") || ob->is_character() || ob_id == "corpse" || ob_id == "skeleton" || ob_id == "huo ba" || ob_id == "deng long" || ob_id == "la zhu"||ob->query("no_drop"))
		{
			tell_object(me,"这件物品不能参加拍卖。\n");
			return 1;
		}
		// 克扣拍卖手续费10%
		
		value = ob->query("value");
		if (value < 30)
		{
			write(ob->query("name") + "一文不值！不能参加拍卖。\n");
			return 1;
		}
		unit = lower_case(unit);
		if(!(num = player_demand(num, unit, me,	"sale"))) return 1;
		guaranty = (int)(num/50);		
		if(!player_pay(me, guaranty)) 
		{
			tell_object(me,"你全部的身家财产尚不足以交纳拍卖保证金！(如果使用银票，请事先兑换)\n");
			return 1;
		}		
		write("你所要拍卖的物品："+ob->query("name")+"， 底价："+MONEY_D->price_str(num)+"\n\n");
		write("请输入你对该物品的介绍（控制在50个字符内）\n直接按回车(enter)可以忽略此项。\n");
		input_to("get_ob_desc",	me, ob_id, num);
		return 1;
	}
	if(sscanf(arg,"%s add %d %s", ob_id,num,unit) == 3)
	{
		
		if(me->query("age") < 18)
		{
			tell_object(me,"你还没有成年，能对自己的拍卖行为负责吗？\n");			
			return 1;
		}


		if(unit != "gold")
		{
			write("现在只接受以黄金(gold)叫价\n");
			return 1;
		}
		if( num < 0 )
		{
			write("请不要做违法事情\n");
			return 1;
		}

		if( num > 5 )
		{
			write("现在限制一次最多家五两黄金以避免不必要的问题产生\n");
			return 1;
		}

		if(me->query("combat_exp") < 3000000)
		{
			tell_object(me,"你虽已成年，但是涉世经验太少，无法对自己的拍卖行为负责。【需要300w经验】\n");
			return 1;
		}
		if(cheat_times && !me->query_temp("auctioning"))
		{
			check_v = values(check);
			check_k = keys(check);
			for(j = 0; j < sizeof(check_v); j++)
			{
				if(me->query("mud_age") - check_v[j] < 3600*cheat_times)	
				{
					tell_object(me,"你由于在某次拍卖过程中信誉值降低，暂时无权参与。\n");
					return 1;
				}
				else map_delete(check, check_k[j]);			
			}
		}
		if((index = member_array(ob_id, ob_key)) == -1)
		{
			for(k = 0; k < sizeof(auction); k++)
			{
				if (strsrch(ob_key[k], ob_id) == -1)
					continue;
				index = k;
			}
			if (index < 0)
			{
				tell_object(me,"目前的拍卖序列中没有这个物品！\n\n指令：auction <物品ID> add <差价值> <货币单位>\n请用auction -l指令查询当前的物品拍卖情况。\n");
				return 1;
			}
		}

		v2 = ob_value[index];
		obj = v2[0];
		ob_price = v2[1];
		ob_id = ob_key[index];
		
		if(objectp(obj)	&& v2[3]	== me)
		{
			tell_object(me,"那是你自己的拍卖物品，想暗地托价不成？\n");
			return 1;
		}
		coin = player_bank(me);
		unit = lower_case(unit);
		if(!(num = player_demand(num, unit, me,	"add"))) return	1;
		
		if ( intp (me->query("paimai/bathtime")) )
		if (uptime() < me->query("paimai/bathtime") + 5 )
			return notify_fail("你才投的标又投，想什么坏主意呢。\n");

		if((int)((num + ob_price)*11/10 > this_player()->query("balance")))
		{
			tell_object(me,"钱庄里没有足够的存款来竞拍卖该物品。（预计价含10%中介费）。\n");
			return 1;
		}


		me->set("discredit/"+ob_id,me->query("mud_age"));
		me->set_temp("auctioning",1);
		v2[1] = num + ob_price;
		v2[2] = me;
		v2[5] = me->query("id");
		str = me->query("name")+"("+me->query("id")+")投标"+v2[7]+"，竞价："+MONEY_D->price_str(v2[1])+"!\n";
		auction_chat(str);
		me->set("paimai/bathtime",uptime() );
		return 1;
	}
	else return help();
}

void get_ob_desc(string	desc, object me, string	str, int num)
{
	write("\n");
	if (strlen(desc) > 60)
	{
		write("您对物品的介绍太长了，请注意言简意赅。\n");
		input_to("get_ob_desc",	me, str, num);
		return ;
	}
	write("作为物主，您是否愿意在拍卖过程中透露自己姓名？(y/n)\n");
	input_to("choise_secret", me, str, desc, num);	
	return;
}

void choise_secret(string yn, object me, string	ob_id, string desc, int	num)
{
	mixed *values;
	string ob_name,	onwer_id, str;
	object ob;

	if (yn[0] != 'y' && yn[0] != 'Y')
		me->set_temp("auction/"+ob_id, "某人");
	else 
		me->set_temp("auction/"+ob_id, me->query("name")+"("+me->query("id")+")");
	if(!objectp(ob = present(ob_id,	me)))
	{
		tell_object(me,"你身上已经没有这件东西了，不能参加拍卖。\n");
		return;
	}		
	if(sizeof(auction) && member_array(ob_id,keys(auction))!= -1)
	{
		tell_object(me,"你晚了一步，这类物品已经被人抢先拍卖了。\n");
		return;
	}
	onwer_id = me->query_temp("auction/"+ob_id);
	ob_name	= ob->query("name")+"("+ob_id+")";

	// 以下设置信任属性，判断违反拍卖规则的玩家
	me->set("discredit/"+ob_id, me->query("mud_age"));
	me->set_temp("auctioning", 1);
	
	values = ({ob, num, "",	me , desc, "", onwer_id, ob_name, ob->long()});
	auction[ob_id] = values;
	str = me->name()+"("+me->query("id")+")启动拍卖进程。";
	CHANNEL_D->do_channel(this_object(),"sys",str);
	str = onwer_id+"现在开始拍卖"+ob_name+"，底价："+MONEY_D->price_str(num)+"。\n";
	auction_chat(str);
	call_out("auction_state_check",	30, 0, 0, num,ob_id);
	return;
}

int player_demand(int num, string unit,	object me, string flag)
{
	switch(unit)
	{
		case "coin":break;
		case "silver":num*=100;break;
		case "gold":num*=10000;break;
		case "cash":
		case "thousand-cash":
			tell_object(me,"拍卖交易中不得使用银票，请先在钱庄兑换成硬通货。\n");
			return 0;
		default:
			tell_object(me,"非法的货币单位！\nvalid	unit: coin, silver, gold\n");
			return 0;
	}
	if (num	< 1000 && flag == "add")
	{
		tell_object(me,"拍卖规则：差价以十两白银为底线。\n");
		return 0;
	}
	if (num	< 1000 && flag == "sale")
	{
		tell_object(me,"对不起，本行不支持无底价拍卖，10两白银是出价底线。\n");
		return 0;
	}
	return num;
}

int player_bank(object ob)
{
	object g_ob;
	object c_ob;
	object s_ob;
	int total;

	total =	ob->query("balance");

	g_ob = present("gold_money", ob);
	c_ob = present("coin_money", ob);
	s_ob = present("silver_money", ob);

	if (g_ob) total	+= g_ob->query_amount()	* 10000;
	if (s_ob) total	+= s_ob->query_amount()	* 100;
	if (c_ob)   total += c_ob->query_amount();
	return total;
}

int player_pay(object who, int amount)
{
	object g_ob, s_ob, c_ob;
	int gc,	sc, cc,	left, total;

	seteuid(getuid());

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	total =	cc + sc	* 100 +	gc * 10000;
	
	if ( total < amount )
	{
		if((amount-total) > who->query("balance"))
			return 0;
		if(objectp(c_ob)) destruct(c_ob);
		if(objectp(s_ob)) destruct(s_ob);
		if(objectp(g_ob)) destruct(g_ob);		
		who->add("balance",-(amount-total)); 
			tell_object(who,"你身上的零钱不够，所需费用已直接从钱庄帐户上扣除。\n\n");
		return 1;
	}
	else 
	{
		left = total - amount;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (g_ob)
			g_ob->set_amount(gc);
		else sc	+= (gc * 100);
		if (s_ob)
			s_ob->set_amount(sc);
		else if	(sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if	(cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who);
		}
		return 1;
	}
}

int help()
{
    write(@HELP命令格式：
 
    查看目前处于竞拍状态的物品清单：paimai -l
    查看目前处于竞拍状态的物品介绍：paimai -i    
    拍卖物品：paimai <物品ID> for <底价值> <货币单位>
    竞拍物品：paimai <物品ID> add <加价值> <货币单位> 
    
    查看详细的拍卖规则：paimai -h
    
HELP
    );
    return 1;
}

int help_2()
{    
    write(@HELP拍卖规则说明文档：  

    1. 玩家在18岁以后，自身经验值达到3000000点即有权利参与拍卖。  
    
    2. 拍卖过程中银票无效，请先去钱庄兑换成硬通货，如黄金、白银、铜钱。
    
    3. 当有人拍卖物品时，拍卖进程正式开始（拍卖底价不得少于10两白银），此时玩家可以
       以至少1两白银（或100文铜钱）的最低差价值参加竞拍，如果一段时间内无人投标，将
       进行喊价，三次喊价后仍然无人出价，则拍卖终止。倘若一直有人投标，到了规定时间，
       此次拍卖活动仍会被终止。拍卖场最大允许5件物品同时拍卖。
       
    4. 拍卖活动终止后，最后出价者为胜，货款从买者手边及钱庄提取，物品直接转移到买者
       身上，如果不堪负重则放在买者所在房间之中，如果房间也无法装下，物品作没收处理，
       切记！物主所得款额直接转至其钱庄帐户。拍卖开始时对卖方收取底价2%的手续费。倘
       若拍卖过程中始终无人投标，拍卖过程宣布失败，手续费恕不退还物主。拍卖成功，买
       方需按成交价交纳10%的中介费。
       
    5. 拍卖过程中，以下行为当作违反拍卖规则处理：买卖双方的任何一人离开游戏导致拍卖
       进程中断；物品离开了物主本人；拍卖结束时买方无力偿付成交价。发生上述情况之一，
       责任方信誉度会降低，惩罚是一小时内不得参加任何与拍卖有关的活动。如果在禁止拍
       卖的时间内再次违规，则禁止时间随违规次数累加。倘若拍卖物品三次喊价之后因为无
       人竞标而取消，卖家在一分钟内不得再拍卖其他物品。
    
       Shure
       2001.8.
HELP
    );
    return 1;
}  

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
