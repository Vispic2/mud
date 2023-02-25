#include <ansi.h>
#define myshops_DIR	"/clone/xianshi/"
inherit NPC;
int ask_xianshi(string arg);
void create()
{
	set_name(HIY"神秘商人"NOR, ( { "shang ren" }));
	set("nickname", "异域商人"NOR);     
	set("long", HIY"这是一位面带紫纱的商人，右手的包裹里貌似藏着什么宝贝。\n"NOR);
	set("gender", "男性");
	set("age", 999);
	set("per", 99);
	set("str", 99);
	set("int", 99);
	set("con", 99);
	set("dex", 99);
	set("qi",99999999);
	set("jingli",99999999);
	set("max_qi", 99999999);
	set("max_jing", 99999999);
	set("eff_jingli", 99999999);
	set("max_neili", 99999999);
	set("neili", 99999999);
	set("jiali", 999);
	set("combat_exp", 99999999);
	set("shen", 99999999);	
	set("inquiry", ([
	"限时抢购" : ""HIY+ZJSIZE(24)+ZJURL("cmds:myshops")+"点击抢购"NOR"",
	
	]));
	setup();
}



void init()
{
	add_action("ask_xianshi","myshops");
}
int ask_xianshi(string arg)
{
object me;
	string str,*all_file,file,price,type,*types;
	int fix,i,yuanbao,value;
	object ob;
	mixed today;
	int jieri,amount;
me=this_player();
	all_file = list_dirs(myshops_DIR);

	if(!sizeof(all_file))
	return notify_fail("商城中赞助商品出售。\n");
	today = localtime(time());
	if((today[4]+1)==1 && today[3]>=1 && today[3]<=3)
	fix = 80;
	else fix = 100;


	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("yuanbao")+"元宝，请选择您想购买的道具：\n"ZJOBACTS2+ZJMENUF(4,4,7,38);
		today = localtime(time());
		

		for(i=0;i<sizeof(all_file);i++)
		{
			file = myshops_DIR+all_file[i];
			if(file_size(file)<0) continue;			
		//	if(file->query("max_buy")<0) continue;									
			yuanbao = file->query("yuanbao");			
			if(yuanbao){
			yuanbao = yuanbao*fix/100;
			if(yuanbao<1) yuanbao = 1;
			}					
			price = yuanbao?(yuanbao+"元宝"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s "ZJBR"%s"ZJBR"限购[%d/%d]:myshops look %s"ZJSEP,file->query("name"),price,query("buy_max/"+file->query("id")),file->query("max_buy"),file);
		}
		write(str+"\n");
		return 1;
	}
	else 	
	if (sscanf(arg,"look %s",file)==1)
	{
		yuanbao = file->query("yuanbao");
			if(yuanbao)
			{
				yuanbao = yuanbao*fix/100;
				if(yuanbao<1) yuanbao = 1;
			}
		price = yuanbao?(yuanbao+"元宝"):(MONEY_D->money_str(file->query("value")));
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "购买1个:myshops buy 1 "+file+ZJSEP"批量购买:myshops buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,myshops_DIR)!=0)
				return notify_fail(HIM"没有这个道具！！"NOR"\n");

			write(INPUTTXT("你想买多少个"+file->query("name")+"？"ZJBR"请确认你的背包空间足够。","myshops buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,myshops_DIR)!=0)
			return notify_fail(HIM"没有这个道具！！"NOR"\n");

		if(amount<1)			
		return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(amount>999)
		return notify_fail(HIM"你要买多少个？？"NOR"\n");
		if(!file->query_amount()&&amount>10)
		return notify_fail(HIM"不可叠加物品一次最多买10个！！"NOR"\n");

		if(file->query("max_buy")){
			if(query("buy_max/"+file->query("id"))+amount>file->query("max_buy"))
			return notify_fail(HIM"此件商品已经抢购完，请下次再来！！"NOR"\n");
		}
		    yuanbao = file->query("yuanbao");
			if(yuanbao){
			yuanbao = yuanbao*fix/100;
			if(yuanbao<1) yuanbao = 1;
			}
		if(!value=file->query("base_value"))
		value = file->query("value");
		if(!yuanbao&&!value)
		return notify_fail(HIM"购买失败！！"NOR"\n");

		if(yuanbao)
		{
			if(!me->query("yuanbao")||me->query("yuanbao")<(yuanbao*amount))
			return notify_fail(HIM"你的元宝不足，请赞助！！"NOR"\n");
			me->add("yuanbao",-yuanbao*amount);
			//log_files("cmds/myshops", sprintf("%s:%s(%s)消费%d元宝，从随身商城购买%d个%s(%s)。\n",ctime(time()),me->query("name"),me->query("id"),yuanbao*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/yuanbao_used",yuanbao*amount);
		}else{
			if(!MONEY_D->player_pay(me, value * amount))
			return notify_fail(HIM"你的钱没那么多了！！"NOR"\n");
			//log_files("cmds/myshopss", sprintf("%s:%s(%s)消费%s，从随身商城购买%d个%s。\n",ctime(time()),me->query("name"),me->query("id"),MONEY_D->money_str(value*amount),amount,file->query("name")));
		}
		if(file->query_amount())
		{
			ob = new(file);
			ob->set_amount(amount);
			write("你从商城中成功购买到"+ob->short()+"。"NOR"\n");
			ob->move(me,1);
		}else{
			for(i=0;i<amount;i++){
				ob = new(file);
				ob->move(me,1);
			}
			write("你从商城中成功购买到"+amount+ob->query("unit")+ob->short()+"。"NOR"\n");
		}
		if(file->query("max_buy")){
		add("buy_max/"+file->query("id"),amount);
		}
		return 1;
	}
	else
	return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
