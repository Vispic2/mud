//vip1 累计赞助100元
//vip2 累计赞助300元
//vip3 累计赞助500元
//vip4 累计赞助800元
//vip5 累计赞助1000元
//vip6 累计赞助1300元
//vip7 累计赞助1500元
//vip8 累计赞助1800元
//vip9 累计赞助2000元
//vip10 累计赞助3000元
inherit NPC;
#include <ansi.h>
string ask_baibao();
int ask_fanli();
int ask_xiandan();
int ask_kuilei();
int ask_viplv();
int ask_lunhui();
string *sk_list = ({
		"qishang-quan",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"baihua-quan",
		"baihua-quan",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"sougu",
		"sougu",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-shenfa",
		"yunlong-shenfa",
		"hanxing-bada",
		"hanxing-bada",
		"huanyin-zhi",
		"zijinbagua-dao",
		"sanfen-jianshu",
		"ningxue-shenzhao",
		"sanfen-jianshu",
		"huanyin-zhi",
		"zijinbagua-dao",
		"xuanming-zhang",
		"ningxue-shenzhao",
		"xuanming-zhang",
		"shenzhaojing",
});
string *sk_list2 = ({
		"qishang-quan",
		"zhuihun-jian",
		"baihua-quan",
		"hanbing-mianzhang",
		"sougu",
		"yunlong-bian",
		"yunlong-shenfa",
		"hanxing-bada",
		"xuanming-zhang",
		"sanfen-jianshu",
		"huanyin-zhi",
		"ningxue-shenzhao",
		"zijinbagua-dao",
		"shenzhaojing",
		"jiuyang-shengong",
});

void create()
{
		set_name(HIW"新人指导"NOR,({  "new", "wushi" }) );
		set("gender", "男性" );
		set("title",HIW"指导师");
		set("age", 30);
		set("long", "这是一个专门为新人指导的NPC。\n");

		set("str", 17);
		set("dex", 16);
		set("con", 15);
		set("int", 17);
		set("shen_type", 1);
		set("combat_exp", 100);
		set("attitude", "peaceful");

		setup();

		set("inquiry", ([
		
	         "葫芦": (: ask_lunhui :),	
	   //      "新人注意说明":"注册后请根据做下角提示的新人指导提示走，直到完成新人指导任务，如果中途退出会出现飞行功能用不了的问题，到时候很麻烦，所以完成新人指导任务时不要退出！",

		]));

		carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	
	add_action("ask_xidian","xidian");
	add_action("do_getvip","getvip");
	add_action("do_getsk","getsk");
}

int accept_fight(object ob)
{
    
        return 0;
}
int accept_kill(object ob)
{
        return 0;
}
int accept_hit(object ob)
{
        return 0;
}

int ask_viplv()
{
	int i,lv;
	object me;
	string str;
int a,b,c,d,e;
	me = this_player();
	str = ZJOBLONG"合理消费，快乐游戏，坚持签到每天来江湖中走一遭，终有一天你会成为一代宗师，加油！"ZJBR"你的vip成就如下：\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,30);
	str += "VIP1[洗心丹1颗]["+((me->query("zjvip/level")>1)?"已达成":"需VIP等级1")+"]["
			+(me->query("zjvip/vipgift/vip1")?"已领取":"未领取")
			+"]:getvip 1"ZJSEP;
	str += "VIP2[九转金丹10颗]["+((me->query("zjvip/level")>2)?"已达成":"需VIP等级2")+"]["
			+(me->query("zjvip/vipgift/vip2")?"已领取":"未领取")
			+"]:getvip 2"ZJSEP;
	str += "VIP3[公共技能随机奖励]["+((me->query("zjvip/level")>3)?"已达成":"需VIP等级3")+"]["
			+(me->query("zjvip/vipgift/vip3")?"已领取":"未领取")
			+"]:getvip 3"ZJSEP;
	str += "VIP4[公共技能自选1次]["+((me->query("zjvip/level")>4)?"已达成":"需VIP等级4")+"]["
			+(me->query("zjvip/vipgift/vip4")?"已领取":"未领取")
			+"]:getvip 4"ZJSEP;			
	str += "VIP5[孟子与鬼谷]["+((me->query("zjvip/level")>5)?"已达成":"需VIP等级5")+"]["
			+(me->query("zjvip/vipgift/vip5")?"已领取":"未领取")
			+"]:getvip 5"ZJSEP;
			
			str += "VIP6[100颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，10串"HIM"神奇葡萄"NOR"，10颗"HIY"九转金丹"NOR"，1块"HIW"石头]["+((me->query("zjvip/level")>6)?"已达成":"需VIP等级6")+"]["
			+(me->query("zjvip/vipgift/vip6")?"已领取":"未领取")
			+"]:getvip 6"ZJSEP;
			str += "VIP7[200颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，20串"HIM"神奇葡萄"NOR"，20颗"HIY"九转金丹"NOR"，1块"HIW"石头"NOR"]["+((me->query("zjvip/level")>7)?"已达成":"需VIP等级7")+"]["
			+(me->query("zjvip/vipgift/vip7")?"已领取":"未领取")
			+"]:getvip 7"ZJSEP;
			str += "VIP8[300颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，30串"HIM"神奇葡萄"NOR"，30颗"HIY"九转金丹"NOR"，1块"HIW"石头"NOR"]["+((me->query("zjvip/level")>8)?"已达成":"需VIP等级8")+"]["
			+(me->query("zjvip/vipgift/vip8")?"已领取":"未领取")
			+"]:getvip 8"ZJSEP;
			str += "VIP9[400颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，40串"HIM"神奇葡萄"NOR"，40颗"HIY"九转金丹"NOR"，1块"HIW"石头"NOR"]["+((me->query("zjvip/level")>9)?"已达成":"需VIP等级9")+"]["
			+(me->query("zjvip/vipgift/vip9")?"已领取":"未领取")
			+"]:getvip 9"ZJSEP;
			str += "VIP10[500颗"HIW"下"HIG"中"HIR"上"HIY"极"NOR"冲脉丹，50串"HIM"神奇葡萄"NOR"，50颗"HIY"九转金丹"NOR"，1块"HIW"石头"NOR"]["+((me->query("zjvip/level")>10)?"已达成":"需VIP等级10")+"]["
			+(me->query("zjvip/vipgift/vip10")?"已领取":"未领取")
			+"]:getvip 10"ZJSEP;
			
			
			
	tell_object(me,str+"\n");
}

int do_getvip(string arg)
{
	int i,lv;
	object ob,me;
	string sk,str;

	me = this_player();
	if(!me->query("zjvip/times"))
	{
		tell_object(me,HIR"你没有vip，不能领取vip成就！\n"NOR);
		return 1;
	}
/*	lv = me->query("zjvip/level");
	if(!arg)
	{
		tell_object(me,HIR"你要干什么！\n"NOR);
		return 1;
	}*/
	if(arg=="1")
	{
		if (me->query("zjvip/all_pay")<100) 
		{
			tell_object(me,HIY"加油，达到vip1你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip1"))
		{
			tell_object(me,HIR"你已经领取过vip1成就奖励了！\n"NOR);
			return 1;
		}
		ob = new("/clone/shizhe/dan_xixin");
		ob->set_amount(1);
		tell_object(me,HIY"你领取到了 1 颗洗心丹！\n"NOR);	
		me->set("zjvip/vipgift/vip1",1);
		ob->move(me);
	}
	
	else if(arg=="2")
	{
		if (me->query("zjvip/all_pay")<300) 
		{
			tell_object(me,HIY"加油，达到vip2你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
	else 
		if(me->query("zjvip/vipgift/vip2"))
		{
			tell_object(me,HIR"你已经领取过vip2成就奖励了！\n"NOR);
			return 1;
		}
		ob = new("/clone/shizhe/dan_jiuzhuan");
		ob->set_amount(10);
		tell_object(me,HIY"你领取到了 10 颗九转金丹！\n"NOR);	
		me->set("zjvip/vipgift/vip2",1);
		ob->move(me);
	}
	
	
	else if(arg=="3")
	{
		if (me->query("zjvip/all_pay")<500) 
		{
			tell_object(me,HIR"你还没有达成该成就，不能领取奖励！\n"NOR);
			return 1;
		}
		else
		 if(me->query("zjvip/vipgift/vip3"))
		{
			tell_object(me,HIR"你已经领取过vip3成就奖励了！\n"NOR);
			return 1;
		}
		if(random(30)==10)
			sk = "jiuyang-shengong";
		else
			sk = sk_list[random(sizeof(sk_list))];

		me->set("zjvip/vipgift/vip3",1);
		if(me->query_skill(sk,1))
		{
			tell_object(me,"你抽中了"+to_chinese(sk)+"，只可惜你已经会了！\n");
			return 1;
		}
		me->set_skill(sk, 180);

		
		if(sk=="jiuyang-shengong")
		{
			tell_object(me, HIY"你得到了一本九阳真经！\n"NOR );
			ob = new("/clone/book/jiuyang-book");
			ob->move(me, 1);
		}
		tell_object(me, HIY"你的"+to_chinese(sk)+"提升到了180级！\n"NOR );
	}
	else
	
	  if(arg=="4")
	{
			if (me->query("zjvip/all_pay")<800) 
		{
			tell_object(me,HIR"你还没有达到vip4，不能领取奖励！\n"NOR);
			return 1;
		}
		else
	    if(me->query("zjvip/vipgift/vip4"))
		{
			tell_object(me,HIR"你已经领取过vip4成就奖励了！\n"NOR);
			return 1;
		}
		str = ZJOBLONG"请选择你想要的技能：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,10,30);
		for(i=0;i<sizeof(sk_list2);i++)
		{
			str += to_chinese(sk_list2[i])+":getsk "+sk_list2[i];
			if(i<(sizeof(sk_list2)-1)) str += ZJSEP;
		}
		tell_object(me,str+"\n");
	}

else if(arg=="5")
	{
		if (me->query("zjvip/all_pay")<1000) 
		{
			tell_object(me,HIY"加油，达到vip5你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip5"))
		{
			tell_object(me,HIR"你已经领取过vip5成就奖励了！\n"NOR);
			return 1;
		}
		ob = new("/clone/shizhe/mengzi");
		ob->move(me);
		//ob->set_amount(1);
		ob = new("/clone/shizhe/guigu");
		//ob->set_amount(1);
		ob->move(me);
		tell_object(me,HIY"你领取到了两本书《孟子》与《鬼谷神算》！\n"NOR);	
		me->set("zjvip/vipgift/vip5",1);
	//	ob->move(me);
	}else if(arg=="6")
	{
		if (me->query("zjvip/all_pay")<1300) 
		{
			tell_object(me,HIY"加油，达到vip6你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip6"))
		{
			tell_object(me,HIR"你已经领取过vip6成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(100);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(10);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(10);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip6",1);	
	}
else if(arg=="7")
	{
		if (me->query("zjvip/all_pay")<1500) 
		{
			tell_object(me,HIY"加油，达到vip7你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip7"))
		{
			tell_object(me,HIR"你已经领取过vip7成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(200);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip7",1);	
	}
else if(arg=="8")
	{
		if (me->query("zjvip/all_pay")<1800) 
		{
			tell_object(me,HIY"加油，达到vip8你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip8"))
		{
			tell_object(me,HIR"你已经领取过vip8成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(300);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(20);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip8",1);	
	}
	
else if(arg=="9")
	{
		if (me->query("zjvip/all_pay")<2000) 
		{
			tell_object(me,HIY"加油，达到vip9你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip9"))
		{
			tell_object(me,HIR"你已经领取过vip9成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(400);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(40);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(40);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip9",1);	
	}
else if(arg=="10")
	{
		if (me->query("zjvip/all_pay")<3000) 
		{
			tell_object(me,HIY"加油，达到vip10你就可以领取成就奖励了哦！\n"NOR);
			return 1;
		}
		else 
		if(me->query("zjvip/vipgift/vip10"))
		{
			tell_object(me,HIR"你已经领取过vip10成就奖励了！\n"NOR);
			return 1;
		}
    ob = new("/clone/vip/dan_chongmai1");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai2");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
    ob = new("/clone/vip/dan_chongmai3");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_chongmai4");
	ob->set_amount(500);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/dan_jiuzhuan");
	ob->set_amount(50);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	ob = new("/clone/vip/putao1");
	ob->set_amount(50);
	write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
	ob->move(me);
	me->set("zjvip/vipgift/vip10",1);	
	}
	return 1;
}

int do_getsk(string arg)
{
	int i,lv;
	object ob,me;
	string sk,str;

	me = this_player();
	if(!me->query("zjvip/times"))
	{
		tell_object(me,HIR"你没有vip，不能领取vip成就！\n"NOR);
		return 1;
	}
	lv = me->query("zjvip/level");
	if(!arg || member_array(arg,sk_list2)==-1)
	{
		tell_object(me,HIR"你要干什么！\n"NOR);
		return 1;
	}
		if (me->query("zjvip/all_pay")<800) 
	{
		tell_object(me,HIR"你还没有达到vip4，不能领取奖励！\n"NOR);
		return 1;
	}
	else
	 if(me->query("zjvip/vipgift/vip4"))
	{
		tell_object(me,HIR"你已经领取过vip4成就奖励了！\n"NOR);
		return 1;
	}
	if(me->query_skill(arg,1))
	{
		tell_object(me,HIY"你选择了"+to_chinese(arg)+"，只可惜你已经会了，请换一个吧！\n"NOR);
		return 1;
	}
	me->set("zjvip/vipgift/vip4",1);
	me->set_skill(arg, 180);
	if(arg=="jiuyang-shengong")
	{
		tell_object(me,HIY "你得到了一本九阳真经！\n" NOR);
		ob = new("/clone/book/jiuyang-book");
		ob->move(me, 1);
	}
	tell_object(me, HIY"你的"+to_chinese(arg)+"提升到了180级！\n"NOR );
	return 1;
}
int ask_fanli()
{
		int i;
		object ob = this_player();
		i=ob->query("zjvip/dizi_pay");	 
		if(ob->query("zjvip/dizi_pay")<1){
				command(HIR"say 你目前的弟子贡献太低，无法领取奖励。"NOR);
				message_vision(HIY"$N已累计获得了"+ob->query("zjvip/dizi_fanli")+"个元宝的奖励。"NOR"\n",ob,  this_object());
				return 1;
		}
		else {
				command("nod "+ob->query("id"));
				command(HIY"say 你已符合领取弟子贡献奖励条件。"NOR);
     			ob->add("yuanbao",i);
				ob->add("zjvip/dizi_pay",-i);
				ob->add("zjvip/dizi_fanli",i);
				message_vision(HIY"$N获得了"+i+"个元宝的奖励。"NOR"\n",ob,  this_object());
				message_vision(HIY"$N已累计获得了"+ob->query("zjvip/dizi_fanli")+"个元宝的奖励。"NOR"\n",ob,  this_object());
				return 1;
		}
}
int ask_xiandan()
{
	int a,b,c,d;
	object ob = this_player();

	a=ob->query("gift/xiandan");
	b=ob->query("gift/unknowdan");
	c=ob->query("gift/shenliwan");
	d=ob->query("gift/xisuidan");
	 
	if (ob->query("zjvip/times") <1) {
		command(HIR"say 对不起，我只处理东方族人的事情！"NOR);
		return 1;
	}
	else {
		command("nod "+ob->query("id"));
		command("say 我来帮你查一下记录。");
		command("say 这位" + RANK_D->query_respect(ob) +"，你已经吃了："+chinese_number(a)+"颗"HIY"醍醐仙丹"NOR"，"+chinese_number(b)+"颗"HIR"火红仙丹"NOR"，"+chinese_number(c)+"颗"HIG"神力丸"NOR"，"+chinese_number(d)+"颗"YEL"洗髓丹"NOR"。");
		return 1;
	}
}

string ask_baibao()
{
	object ob;
	mapping myfam;
	object nang;

	ob = this_player();
	myfam = (mapping)ob->query("family");
		
	//if(!myfam) return "你还是先加入门派吧？";

	if (ob->query("combat_exp") < 10000)
		return ""HIR"虽然我这里有只乾坤袋，可是你战斗经验这么差，被人抢走了怎么办？"NOR"\n";

	if (ob->query("chuwudai"))
		return ""HIR"你之前不是已经领过了吗？你还是赶紧联系管理员去处理一下吧。"NOR"\n";
		
	if ( present("chuwu dai", ob))
		return ""HIR"你已经有了一个储物袋，别贪得无厌！"NOR"\n";

	nang=new("/clone/misc/baibao");
	nang->set("owner_id", ob->query("id"));
	nang->move(ob);
	ob->set("chuwudai", 1);
	write(HIY"你得到一个储物袋!\n"NOR);
	return ""HIY"这可是个宝贝，好好利用它吧。"NOR"";
}

int ask_kuilei()
{
	object ob = this_player();
	object yao;
	int last = ob->query("zjvip/last_get_kuilei");
	int now = time();
	 
	if (ob->query("zjvip/times") <1) {
		command(HIR"say 对不起，我只处理东方族人的事情！"NOR);
		return 1;
	}
	if ((ob->query("zjvip/all_pay")+ob->query("gongxians"))<100) {
		command(HIR"say 对不起，你的贡献不够，不符合领取替身傀儡的条件！"NOR);
		return notify_fail("对不起，你的贡献不够，不符合领取的条件【需要100贡献】！\n");
	}
	if(localtime(last)[4] != localtime(now)[4])
	{
		ob->set("zjvip/last_get_kuilei",now);
		ob->delete("zjvip/get_kuilei");
	}

	if (ob->query("zjvip/get_kuilei")>=((ob->query("zjvip/all_pay")+ob->query("gongxians"))/200)) {
		command(HIR"say 以你目前的贡献只能领"+chinese_number((ob->query("zjvip/all_pay")+ob->query("gongxians"))/1000)+"个替身傀儡！"NOR);
		return 1;
	}

	command("nod "+ob->query("id"));
	command(HIY"say 我这就给你。"NOR);
	yao = new("/clone/shizhe/kuilei");
	yao->move(ob);
	ob->add("zjvip/get_kuilei",1);

	message_vision("$N给了$n一个" + yao->query("name") + "。\n",this_object(),ob);
	//log_files("gift", sprintf(ob->query("id")+"在%s：领取了一个替身傀儡。\n",ctime(time())));
	return 1;
		
}

int ask_lunhui()
{
	object ob = this_player();
	object yao;
	
    
    
	command("nod "+ob->query("id"));
	command(HIY"say "NOR);
	yao = new("/d/newtt/obj/hulu");
	yao->move(ob);
	yao = new("/d/newtt/obj/yeguo");
	yao->move(ob);
	write(HIW"欢迎来到"+LOCAL_MUD_NAME()+"。\n"NOR);
	write(HIW"新人指导拿出一个葫芦跟野果给你。\n"NOR);
//	message_vision("$N拿出一个" + yao->query("name") + "。\n",this_object(),ob);
//	//log_files("zhuanshis", sprintf(ob->query("id")+"在%s：领取了一粒轮回丹。\n",ctime(time())));
	return 1;
		
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
