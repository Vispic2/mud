//by 游侠 ranger's ednpc tools.
// shanzei1.c
//灵脉副本，大量黄金。
#include <ansi.h>
inherit NPC;

string *random_ob = ({
    "/clone/money/gold",
    "/clone/vip/putao",
});

void create()
{

	set_name(HIC"小灵脉"NOR,({"ling"}));
	set("gender", "男性");
	set("per",20);
	set("age", 20);
	set("combat_exp", 1000000+random(1000000));
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	//set("qi_no",1);
	set("max_neili", 5000+random(5000));
	set("neili", 5000+random(5000));
	set("eff_qi", 5000+random(5000));
	set("max_qi", 5000+random(5000));
	set("qi", 5000+random(5000));
	set("max_jing", 5000+random(5000));
	set("jing", 5000+random(5000));
	set("max_jingli", 5000+random(5000));
    set("eff_jingli", 5000+random(5000));
 	set("jingli", 5000+random(5000));
		
	set_skill("force", 100+random(101));
	set_skill("dodge", 100+random(101));
	set_skill("unarmed", 100+random(101));
	set_skill("parry", 100+random(101));
    set_skill("shaolin-xinfa", 100+random(101));	
    set_skill("shaolin-shenfa", 100+random(101));
    set_skill("changquan", 100+random(101));	   
     	    	
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defence",100);
	set_temp("apply/armor", 1000);
	
	map_skill("force", "shaolin-xinfa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "chanquan");
	map_skill("parry", "chanquan");		
	setup();
}

void die()
{
   string id = random_ob[random(sizeof(random_ob))];//随机物品
   object killer,ob;
   int exp;
   int a,b,c;
	if (objectp(killer = query_last_damage_from()))
	{
//	a=20+random(20);
	b=500+random(50);
	//c=1+random(1);
//		killer->add("combat_exp",a);
		killer->add("potential",b);
	//	killer->add("yuanbaos",c);
		tell_object(killer,"你杀死"+name()+"，"+b+"点潜能。\n");
	}
	
	switch (random(10))
	{		
		case 5 :		
		new(id)->move(killer);
        CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在《灵脉山洞》获得了"+id->short()+"。");									
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
