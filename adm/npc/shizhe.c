#include <ansi.h>
inherit NPC;
string ask_lilian();
string ask_jieshu();
string ask_baotu();;
string ask_yao();
int ask_xflb();
int ask_xflbs();
int ask_xflbss();
int ask_xflbsss();
int ask_xflbssss();
int ask_cqsmk3();
int ask_cqsmk4();
int ask_cqsmk5();
int ask_cqsmk6();
int ask_cqsmk();
int ask_yb();
int ask_yb2();
int ask_yb3();
int ask_dzlb();
int ask_sdlb();
int ask_ydlb();
void create()
{
	set_name(YEL"江湖使者"NOR, ( { "ta jian" }));
	set("nickname", HBRED"仙界武神"NOR); 
     set("title", HBRED "十步杀一人，千里不留行！" NOR);
	set("long", HIW"这是一位来自天上的天仙，他长相英俊潇洒，让人一见就心生喜欢。\n"NOR);
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
		"历练" : (: ask_lilian :),
		"结束" : (: ask_jieshu :),
		"护心丹" : (: ask_yao :),
		"藏宝图" : (: ask_baotu :),
		"新人礼包" : (: ask_xflb :),
	//"测试礼包" : (: ask_xflbs :),
    "开服礼包" : (: ask_xflbss :),
	"新人助力" : (: ask_xflbsss :),
	"重启补偿" : (: ask_xflbssss :),
	"重启补偿2" : (: ask_cqsmk :),
	"重启补偿3" : (: ask_cqsmk3 :),
	"重启补偿4" : (: ask_cqsmk4 :),
	"重启补偿5" : (: ask_cqsmk5 :),
	"重启补偿6" : (: ask_cqsmk6 :),
	"元宝礼包1" : (: ask_yb :),
	"元宝礼包2" : (: ask_yb2 :),
	"元宝礼包3" : (: ask_yb3 :),
	"冬至礼包" : (: ask_dzlb :),
	"圣诞礼包" : (: ask_sdlb :),
	"元旦礼包" : (: ask_ydlb :),
	
	]));
	setup();
}



void init()
{
	object ob;
	::init();//继承上一级
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
	add_action("ljshop","ljshop");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("zjvip/times") > 0 && !ob->query("lilian/start"))
	{
		command("hi "+ob->query("id"));
		command("whisper "+ob->query("id")+" "HIC"\n这位" + RANK_D->query_respect(ob) +"你是我们东方一族的成员，\n"+
		        "你还没有在我这里"HIC""ZJURL("cmds:ask ta jian about 历练")+ZJSIZE(20)"登记"NOR""HIR"历练"HIC"，\n"+
		        "赶紧开始你的"HIR"历练"HIC"，领取丰厚的家族奖励吧！"NOR"");
	}

}


int ask_yb()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/wuxianyuanbao"))
	{
		tell_object(me,"你已经领取过元宝礼包了，不能重复领取！\n");
		return 1;
	}

me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
me->set("zjvip/wuxianyuanbao",1);
return 1;
}
int ask_yb2()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/wuxianyuanbao2"))
	{
		tell_object(me,"你已经领取过元宝礼包了，不能重复领取！\n");
		return 1;
	}

me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100000);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100000充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
me->set("zjvip/wuxianyuanbao2",1);
return 1;
}

int ask_yb3()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/wuxianyuanbao3"))
	{
		tell_object(me,"你已经领取过元宝礼包了，不能重复领取！\n");
		return 1;
	}

me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100000);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100000充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
me->set("zjvip/wuxianyuanbao3",1);
return 1;
}
int ask_dzlb(){
	object me = this_player();
		object blf,sj;
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n"); 
 
if (me->query("dzlb2022"))
	{
		tell_object(me,"你已经领取过冬至礼包了，不能重复领取！\n");
		return 1;
	}

 blf = new("/clone/shizhe/buluofen");
 blf->set_amount(10);
 blf->move(me);
 tell_object(me,HIM"你获得了"+blf->short()+"。"NOR"\n");
 
 sj = new("/clone/shizhe/shuijiao");
 sj->set_amount(10);
 sj->move(me);
 tell_object(me,HIM"你获得了"+sj->short()+"。"NOR"\n");
me->set("dzlb2022",1);
return 1;
}

int ask_sdlb(){
	object me = this_player();
		object pg;
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n"); 
 
if (me->query("sdlb2022"))
	{
		tell_object(me,"你已经领取过圣诞礼包了，不能重复领取！\n");
		return 1;
	}


 //message_vision(HIG"$N翻开记事簿，对$n点了点头，说道：好吧，我这就为你记上。"NOR"\n",me,ob);
 pg = new("/clone/gift/gift_christmas");
 pg->set_amount(10);
 pg->move(me);
 tell_object(me,HIM"你获得了"+pg->short()+"。"NOR"\n");
me->set("dzlb2022",1);
return 1;
}
int ask_ydlb(){
	object me = this_player();
		object pg;
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n"); 
 
if (me->query("ydlb2022"))
	{
		tell_object(me,"你已经领取过元旦礼包了，不能重复领取！\n");
		return 1;
	}


 //message_vision(HIG"$N翻开记事簿，对$n点了点头，说道：好吧，我这就为你记上。"NOR"\n",me,ob);
 pg = new("/clone/shizhe/zhou");
 pg->set_amount(5);
 pg->move(me);
 tell_object(me,HIM"你获得了"+pg->short()+"。"NOR"\n");
me->set("ydlb2022",1);
return 1;
}
int ask_xflb()
{
	object ob = this_player();
	object gift;
	int num,money;

	if (ob->query("zjvip/kaihuang_gift"))
	{
		tell_object(ob,"你已经领取过新手礼包了，不能重复领取！\n");
		return 1;
	}

	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/shizhe/xslb");
	tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/kaihuang_gift",1);
	//log_files("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}

int ask_xflbs()
{
	object ob = this_player();
	object a1,a2,a3,a4;	
	if (ob->query("zjvip/kaihuang_gifts")){
		tell_object(ob,"你已经领取过测试礼包了，不能重复领取！\n");
		return 1;
	}
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	a1 = new("/clone/shizhe/putao1");
	a1->move(ob);
	a1->move(ob);
	a1->move(ob);			
	tell_object(ob,HIR"你获得了"+a1->short()+"。"NOR"\n");	
	ob->set("zjvip/kaihuang_gifts",1);	
	return 1;
}
int ask_xflbss()
{
	object ob = this_player();
	object a1,a2;	
	if (ob->query("zjvip/kaihuang_giftss")){
		tell_object(ob,"你已经领取过新人助力礼包了，不能重复领取！\n");
		return 1;
	}
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	a1 = new("/clone/shizhe/jiuzhuan1");
	a1->move(ob);
	tell_object(ob,HIG"你获得了"+a1->short()+"。"NOR"\n");	
	a2 = new("/clone/shizhe/dan_jiuzhuan");
	a2->move(ob);
	tell_object(ob,HIG"你获得了"+a2->short()+"。"NOR"\n");	
	ob->set("zjvip/kaihuang_giftss",1);	
	return 1;
}
int ask_xflbsss()
{
	object ob = this_player();
	object a1;	
	if (ob->query("zjvip/kaihuang_giftsss")){
		tell_object(ob,"你已经领取过新人助力礼包了，不能重复领取！\n");
		return 1;
	}
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	ob->add("combat_exp",1500000);
	ob->add("potential",1000000);
	tell_object(ob,HIG"你获得了经验150万点，潜能100万点。"NOR"\n");	
	ob->set("zjvip/kaihuang_giftsss",1);	
	return 1;
}

int ask_xflbssss()
{
	object ob = this_player();
	object fei;	
	if (ob->query("zjvip/kaihuang_giftsssss")){
		tell_object(ob,"你已经领取过重启补偿礼包了，不能重复领取！\n");
		return 1;
	}
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");	
	fei = new("/clone/shizhe/putao1");
	fei->set_amount(20);
	fei->move(ob);
	tell_object(ob,HIM"恭喜您：获得了"+fei->short()+"。"NOR"\n");
	ob->set("zjvip/kaihuang_giftsssss",1);	
	return 1;
}
int ask_cqsmk()
{
	object ob = this_player();
	object fei;	
	if (ob->query("zjvip/chongqibuchang2")){
		tell_object(ob,"你已经领取过重启补偿2礼包了，不能重复领取！\n");
		return 1;
	}
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");	
	fei = new("/clone/shizhe/shimenka");
	fei->set_amount(5);
	fei->move(ob);
	tell_object(ob,HIM"恭喜您：获得了"+fei->short()+"。"NOR"\n");
	ob->set("zjvip/chongqibuchang2",1);	
	return 1;
}

int ask_cqsmk3()
{
	object ob = this_player();
	object fei;	
	if (ob->query("zjvip/chongqibuchang3")){
		tell_object(ob,"你已经领取过重启补偿3礼包了，不能重复领取！\n");
		return 1;
	}
	command("nod "+ob->query("id"));
	command("say 我这就发给你。");	
	fei = new("/clone/shizhe/putao3");
	fei->set_amount(100);
	fei->move(ob);
	tell_object(ob,HIM"恭喜您：获得了"+fei->short()+"。"NOR"\n");
	ob->set("zjvip/chongqibuchang3",1);	
	return 1;
}

int ask_cqsmk4()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/chongqibuchang4"))
	{
		tell_object(me,"你已经领取过元宝礼包了，不能重复领取！\n");
		return 1;
	}

me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100000);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100000充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
me->set("zjvip/chongqibuchang4",1);
return 1;
}

int ask_cqsmk5()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/chongqibuchang5"))
	{
		tell_object(me,"你已经领取过元宝礼包了，不能重复领取！\n");
		return 1;
	}

me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100000);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100000充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
me->set("zjvip/chongqibuchang5",1);
return 1;
}
int ask_cqsmk6()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/chongqibuchang6"))
	{
		tell_object(me,"你已经领取过元宝礼包了，不能重复领取！\n");
		return 1;
	}

me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100000);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100000充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
me->set("zjvip/chongqibuchang6",1);
return 1;
}

string ask_lilian()
{
	object me = this_object();
	object ob = this_player();

	if (ob->query("vip/all_pay")>0)
	{
		ob->add("zjvip/all_pay",ob->query("vip/all_pay"));
		ob->delete("vip/all_pay");
	}

	if (ob->query("zjvip/times") <1) return "对不起，我只处理东方族人的事情！\n";

	if (ob->query("lilian/start")) return "我已经记录了你的历练信息，放心去吧。\n";

	message_vision(HIG"$N翻开记事簿，对$n点了点头，说道：好吧，我这就为你记上。"NOR"\n",me,ob);

	ob->set("lilian/start",time());

	return "别忘了在六个时辰内找我结束历练。\n";
}

string ask_jieshu()
{
	  object me = this_object();
	  object ob = this_player();
        int time3, paid,exp,gold;

        time3=time()-(int)ob->query("lilian/start");

        if (ob->query("zjvip/times") <1) return "对不起，我只处理东方家族的事情！\n";

        if (!ob->query("lilian/start")) return "我这里没有你的历练记录。\n";

        paid=ob->query("zjvip/all_pay");

        tell_object(ob,HIC"你的累计历练时间是"+CHINESE_D->chinese_time(time3)+"。"NOR"\n");  

        if (time3>43200) time3=43200;

        tell_object(ob,HIC"你的有效历练时间是"+CHINESE_D->chinese_time(time3)+"。"NOR"\n");  
	  message_vision(HIY"$N结束了$n的本次历练！"NOR"\n",me,ob);
        ob->add("balance",time3*4);
        ob->add("combat_exp",time3/2);
        ob->add("potential",time3/14);
        ob->delete("lilian/start");
        tell_object(ob,"你被奖励了\n"
                       "白银："+time3*4/100+" 两，\n"
                       "经验："+time3/2+" 点，\n"
                       "潜能："+time3/14+" 点。"NOR"\n");  


        exp=time3*paid/1000;
        if (exp>time3) exp=time3;
        gold=time3*paid/500;
        if (gold>time3) gold=time3;

        

        ob->add("balance",gold*2);
        ob->add("combat_exp",exp/4);
        //tell_object(ob,"根据你的贡献度，你额外获得了"+gold*2/100+"两白银和"+exp/4+"点经验。"NOR"\n"); 

	  return "根据你的贡献度，额外奖励你"+gold*2/100+"两白银和"+exp/4+"点经验。"NOR"\n";
}

string ask_baotu()
{
	int now,last,nowfix,lastfix;
	mixed *t1,*t2;
	object tu,me = this_player();

	if (me->query("zjvip/times") <1) return "对不起，我只处理地狱家族的事情！\n";
	if (me->query("zjvip/times") < 10*24*3600) return "对不起，会员时长已不足10天，不能领取藏波图！\n";
	last = me->query("zjvip/last_baotu");
	now = time();
	t1 = localtime(now);
	t2 = localtime(last);
	nowfix = now+(6-t1[6])*86400;
	lastfix = last+(6-t2[6])*86400;
	if(last&&(localtime(nowfix)[7]==localtime(lastfix)[7]))
		return "一周内只能领一次！\n";
	if ((me->query_encumbrance()*100 / me->query_max_encumbrance())>90)
		return "你身上的东西太多了！\n";
	if ( (time()-me->query("birthday")) < 7*86400 )
		return "你还是等下周再来领取藏宝图吧！\n";

	tu = new("/d/fuben/obj/heifeng1");
	tu->move(me);
	me->set("zjvip/last_baotu",now);
	message_vision("使者给了$N一张" + tu->query("name") + "。\n",me);
	log_file("adms/vip_tu",ctime(time())+"："+me->query("name")+"在地狱使者那里领取一张藏宝图。\n");
	return "这可是好东西，你抽空找朋友一起去探索一下吧。\n";
}

string ask_yao()
{
	object me = this_object();
	object ob = this_player();
        object yao;

	if (ob->query("zjvip/times") <1) return "对不起，我只处理地狱家族的事情！\n";

        if ( (time()-ob->query_temp("last_huxindan"))<1800 ) {
		    command("say 这位" + RANK_D->query_respect(ob) + "，你不是刚刚来领过天王护心丹吗，怎么又来要了？");
                ob->unconcious();
                return "真是讨打！";
            }

        if (  present("huxin dan", ob) )
                return RANK_D->query_respect(ob) + "你身上不是已经有天王护心丹了吗，怎么又来要了？ 真是贪得无厌！";

        if (objectp(present("huxin dan", environment(ob))))
                        return "曾经有一颗天王护心丹落你的眼前，你却没有好好珍惜...\n";

        if ((ob->query_encumbrance()*100 / ob->query_max_encumbrance())>90)
                return "你身上的东西太多了！\n";

        yao = new("/clone/shizhe/huxindan9");
        yao->set_amount(99);
        yao->move(ob);
        ob->set_temp("last_huxindan",time());
        message_vision("$N给了$n一些" + yao->query("name") + "。\n",me ,ob);
	return "这可是好东西，希望对你行走江湖有所帮助。\n";
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
