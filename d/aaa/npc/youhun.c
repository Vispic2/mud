#include <ansi.h>
//inherit NPC;
inherit CLASS_D("generate") + "/chineses";
private void init_player(object me);
string *random_ob = ({      
   "/clone/shizhe/putao1",  //神奇葡萄   
   "/clone/shizhe/putao",  //葡萄
   "/clone/shizhe/dan_chongmai1",  //下品冲脉丹
   "/clone/shizhe/putao",  //葡萄
   "/clone/shizhe/dan_chongmai1",  //下品冲脉丹
   "/clone/money/yuanbao",   //元宝
   "/clone/shizhe/jinsha",    //金砂
   "/clone/shizhe/book_wuliang", //无良经书
   "/clone/shizhe/book_tianfu",     //初级天赋书
   "/clone/shizhe/cagate", //玛瑙残片
   "/clone/shizhe/ccrystal",  //水晶残片
   "/clone/shizhe/cjade",   //翡翠残片
   "/clone/shizhe/cdiamond",   //钻石碎粒
   "/clone/shizhe/cagate", //玛瑙残片
   "/clone/shizhe/ccrystal",  //水晶残片
   "/clone/shizhe/cjade",   //翡翠残片
   "/clone/shizhe/cdiamond",   //钻石碎粒
   "/clone/shizhe/tuzhi",  //刺青图纸
   "/clone/shizhe/tuzhi",  //刺青图纸
   "/clone/shizhe/tuzhi",  //刺青图纸
   "/clone/shizhe/tuzhi",  //刺青图纸
   "/clone/shizhe/tuzhi",  //刺青图    
   "/clone/shizhe/shimenka",  //刺青图        
});

void create()
{
	::create();
	set_name(BLU"幽魂"NOR,({"hun"}));
	set("gender", "野兽");
	set("long", HIR"这是一只幽魂！\n"NOR);

	set("per",30);
	set("age", 30);
	set("combat_exp",999999);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("max_neili", 200000);
	set("neili", 200000);
	set("eff_qi", 200000);
	set("max_qi", 200000);
	set("qi", 200000);
	set("max_jing", 200000);
	set("jing", 200000);
	set("max_jingli", 200000);
    set("eff_jingli", 200000);
 	set("jingli", 200000);
	set("dex", 30);
	set("no_look",1);
	set("qi_no",1);
	set("no_touxi",1);			
		if (clonep(this_object()))
	{
		set("chat_chance", 30);
		set("chat_msg", ({ (: random_move :) }));
		set("born_time", time());
		keep_heart_beat();
	}
	setup();
}
void set_from_me(object me)
{
	int exp;

	NPCS_D->init_npc_skill(this_object(), NPCS_D->check_level(me));
}
int accept_fight(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_hit(object ob)
{

   return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_ansuan(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}

int accept_touxi(object ob)
{
	return notify_fail("那人警惕性好高，你难以下手。\n");
}
int accept_kill(string arg)
{
    
	object ob=this_object();
	object me=this_player();
	int kill,room;
	object where = environment(me);
    if (me->is_fighting())
	return notify_fail("你正在战斗呢。\n");
	if (me->is_busy())
	return notify_fail("你正在战斗呢。\n");
	me->set("dizhi",where);
	me->set("npc/npc",1);
	write("地址:"+me->query("dizhi")+"\n");
	if(query("zd") >= 3)
	{	
		destruct(ob);	
		return 0;
	}
	else
	{
	kill=new("/d/aaa/npc/youhun");
	NPCS_D->set_from_me(kill, me, 250);
	init_player(me);
	room=new("/d/aaa/main");	
	kill->move(room);
	kill->set("no_look",0);
	me->move(room);
	kill_ob(me);
	me->kill_ob(kill);
	add("zd",1);
	write("请小心！战斗开始！\n");
	return 1;
	}
	return 1;
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer=this_player(),ob;	
	int exp,pot,com,yuanbao,yuanbaos;
	int a;
	if (objectp(killer = query_last_damage_from()))
	{
	com=150+random(150);
	pot=100+random(100);
	exp=50+random(50);
	yuanbaos=1+random(2);
	killer->add("combat_exp",com);
	killer->add("potential",pot);
	killer->add("experience",exp);
	killer->add("yuanbaos",yuanbaos);	
	killer->move(killer->query("dizhi"));
	if(random(50)==25)
	{
	a = new("/clone/money/gold");
    a->move(killer);
	tell_object(killer,"你杀死"+name()+"，获得了("+com+")点经验，("+pot+")潜能，("+exp+")实战，("+yuanbaos+")元宝票，恭喜你额外获得了一两"+HIY+"黄金"+NOR+"！\n");
	}else
	
	{
	tell_object(killer,"你杀死"+name()+"，获得了("+com+")点经验，("+pot+")潜能，("+exp+")实战，("+yuanbaos+")元宝票！\n");
	
	}
	
	}	
	switch (random(10))
	{
		
		case 5 :
		case 9 :
		new(id)->move(killer);
        CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在驱赶幽魂途中获得了"+id->short()+"。");									
		break;
	}
    	::die();
    }

void unconcious()
{
	die();
}


private void init_player(object me)
{
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));	
}

int check_out(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n你觉得眼前一黑，什么也不记得了！"NOR"\n");
	me->move(me->query("dizhi/qilin"));
	if(me->is_busy())
	me->interrupt_me(me,me->query_busy());
	if (! living(me))
	me->revive();
	return 1;
}


void random_move()
{
	if (time() - query("born_time") > (300+random(100)))
	{
		message_vision("$N消失再你眼前。\n", this_object());
//		CHANNEL_D->do_channel(this_object(), "rumor","听说" + name() + HIM "测试成功了。" NOR);
		destruct(this_object());
		return;
	}
//	NPC_D->random_move(this_object());
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
