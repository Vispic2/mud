//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;
//蒙古副本，产出兵符

string *random_ob = ({
    "/fuben/wuguan/obj/putao",
});

void create()
{

int lvl = 5000;

	set_name(HIC"蒙古兵"NOR,({"menggu bing"}));
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
		
	set_skill("force", 100+random(51));
	set_skill("dodge", 100+random(51));
	set_skill("unarmed", 100+random(51));
	set_skill("parry", 100+random(51));
    set_skill("shaolin-xinfa", 100+random(51));	
    set_skill("shaolin-shenfa", 100+random(51));
    set_skill("changquan", 100+random(51));	    	    	
	
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
	a=700+random(70);
	b=350+random(35);
//	c=1+random(1);
		killer->add("combat_exp",a);
		killer->add("potential",b);
		killer->add("yuanbaos",c);
		tell_object(killer,"你杀死"+name()+"，获得"+a+"点经验，"+b+"点潜能。\n");
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
