#include <ansi.h>
inherit NPC; 
int ask_xnlb(); 
void create()
{
	set_name(HIR"新年礼包使者"NOR, ( { "er shi" }));
	set("nickname", HBRED"快乐使者"NOR); 
     set("title", HBRED "新年快乐恭喜发财！" NOR);
	set("long", HIW"这是一位来自天上的神仙，他长相英俊潇洒，让人一见就心生喜欢。\n"NOR);
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
	"新年礼包" : (: ask_xnlb :),
	
	]));
	setup();
}



void init()
{
	object ob;
	::init();//继承上一级 
}
 
int ask_xnlb()
{
object me = this_player();
if (me->is_busy())
return notify_fail("你还是先停下手头里的事情再说吧！\n");
if(me->query("yuanbao")>=1000000){
tell_object(me,"你身上已经有100W元宝了，请先使用完后再来领取！\n");
return 1;
}
if (me->query("zjvip/2023xnlb"))
	{
		tell_object(me,"你已经领取过新年礼包了，不能重复领取！\n");
		return 1;
	}
me->add("zzjianglii",10);
me->add("yuanbao",100000);
me->add("yuanbaos",100000);
me->add("zjvip/all_pay",100000);
tell_object(me,HIG"恭喜你获得："HIY"100000元宝，100000元宝票，""100000充值贡献。\n"HIW"支持本服务器的联系QQ：21315491，支持的钱会用于续费服务器。"NOR"\n");	
tell_object(me,HIG"恭喜你获得：10次获取随机武功的机会。"HIR"注意！抽到已有武功将替换已有武功技能！。\n"NOR"\n");	
me->set("zjvip/2023xnlb",1);
return 1;
}
 

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
