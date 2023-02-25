//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
    "/fuben/wuguan/obj/putao",
    "/fuben/wuguan/obj/dan_chongmai1",
    "/fuben/wuguan/obj/book_wuliang",
    "/fuben/wuguan/obj/book_tianfu",  
    "/clone/shizhe/shimenka",   
   
});

void create()
{
int lvl = 8000;

	set_name(HIR"蒙古统帅"NOR,({"menggu tongshuai"}));
	set("gender", "男性");
	set("per",20);
	set("age", 20);
	set("combat_exp", 1000000+random(1000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl);
	set("neili", lvl);
	set("eff_qi", lvl);
	set("max_qi", lvl);
	set("qi", lvl);
	set("max_jing", lvl);
	set("jing", lvl);
	set("max_jingli", lvl);
    set("eff_jingli", lvl);
 	set("jingli", lvl);
		
	set_skill("force", 150+random(51));
	set_skill("dodge", 150+random(51));
	set_skill("unarmed",150+random(51));
	set_skill("parry", 150+random(51));
    set_skill("shaolin-xinfa", 150+random(51));	
    set_skill("shaolin-shenfa", 150+random(51));
    set_skill("changquan", 150+random(51));	    	    	
	
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
	a=100+random(100);
	b=50+random(50);
	c=1+random(1);
		killer->add("combat_exp",a);
		killer->add("potential",b);
		//killer->add("yuanbaos",c);
		
	if(random(3)==2)
	{
	a = new("/clone/shizhe/bingfu");
    a->move(killer);
    tell_object(killer,"你杀死"+name()+"，获得"+a+"点经验，"+b+"点潜能，并且获得了兵符！\n");
    CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在守卫襄阳中侥幸击杀了蒙古统帅获得了【兵符】。");									
	}
	else
	
	{
		tell_object(killer,"你杀死"+name()+"，获得"+a+"点经验，"+b+"点潜能。");

	}
		}
	
	switch (random(10))
	{
		case 0 : 
		case 5 :
		case 9 :
			new(id)->move(killer);
CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在守卫襄阳获得了"+id->short()+"。");									
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
