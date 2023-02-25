#include <ansi.h>
inherit NPC;
string *random_ob = ({      
   "/clone/shizhe/putao",  //葡萄
   "/clone/shizhe/putao1",  //大葡萄
   "/clone/shizhe/dan_chongmai1",  //下品冲脉丹
   "/clone/shizhe/shimensssss",    //自动师门符
   "/clone/shizhe/shimensssss",   //自动师门符
   "/clone/money/yuanbao",   //元宝
   "/clone/shizhe/jinsha",    //金砂
   "/clone/shizhe/book_wuliang", //无良经书
   "/clone/shizhe/book_tianfu",     //初级天赋书
    "/clone/shizhe/cagate", //玛瑙残片
    "/clone/shizhe/ccrystal",  //水晶残片
    "/clone/shizhe/cjade",   //翡翠残片
    "/clone/shizhe/cdiamond",   //钻石碎粒
    "/clone/shizhe/cdiamond",   //钻石碎粒
     "/clone/shizhe/tuzhi",  //刺青图纸
        
});
void create()
{
	set_name(HIB"幽魂[中级]"NOR,({"you hun ss"}));
	set("gender", "男性");
	set("long", "中级幽魂挑战的经验必须低于800经验。\n");
	set("per",30);
	set("age", 30);
	set("combat_exp",99999999);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("no_touxi",1);
	set("max_neili", 150000);
	set("neili", 150000);
	set("eff_qi", 15000);
	set("max_qi", 15000);
	set("qi", 15000);
	set("max_jing", 15000);
	set("jing", 15000);
	set("max_jingli", 15000);
    set("eff_jingli", 15000);
 	set("jingli", 15000);
			
	set_skill("sword",300+random(200));
	set_skill("unarmed",300+random(200));
	set_skill("force",300+random(200));
	set_skill("parry",300+random(200));
	set_skill("dodge",300+random(200));
	set_skill("pixie-jian",300+random(200));					
	map_skill("sword", "pixie-jian");			
	map_skill("unarmed", "pixie-jian");			
	map_skill("force", "pixie-jian");			
	map_skill("parry", "pixie-jian");			
	map_skill("dodge", "pixie-jian");				
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "force.pi" :),
		(: perform_action, "force.powerup" :),
		(: exert_function, "force.shield" :),	
	}));
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();

	setup();
}

int accept_kill(object me)
{
	// if (me->query("combat_exp") > 8000000)
	// {
	// 	message_vision( "经验高于800w不能挑战中级幽魂。\n",this_object(), me);
	// 	me->move("/d/city/kedian");
	// 	return -1;
	// }
    	
	command("sigh");
	command("say 受死吧！");
	return 1;
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp,pot,com,yuanbao,yuanbaos;
	if (objectp(killer = query_last_damage_from()))
	{
	com=1500+random(1500);
	pot=1000+random(1000);
	exp=500+random(500);
	yuanbao=2+random(5);
	yuanbaos=2+random(5);
	killer->add("combat_exp",com);
	killer->add("potential",pot);
	killer->add("experience",exp);
	killer->add("yuanbao",yuanbao);
	killer->add("yuanbaos",yuanbaos);	
	tell_object(killer,"你杀死"+name()+"，获得了("+com+")点经验，("+pot+")潜能，("+exp+")实战，("+yuanbao+")元宝，("+yuanbaos+")元宝票。\n");
	}	
	switch (random(10))
	{
		case 0 : 
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
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
