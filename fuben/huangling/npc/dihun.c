//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
//inherit NPC;
inherit CLASS_D("generate") + "/chineses";
string *random_ob = ({
   "/clone/shizhe/putao1",
    "/clone/shizhe/dan_chongmai3",
    "/clone/shizhe/tianling",    
    "/clone/shizhe/jinsha",
    "/clone/shizhe/book_wuliang",
    "/clone/shizhe/book_tianfu2",
    "/clone/shizhe/shimenka",
});

void create()
{
object ob = this_player();
	::create();
	set_name(HIY"帝魂"NOR,({"di hun"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 9999999+random(3000000));
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
    set("max_neili", 50000);
	set("neili", 50000);
	set("eff_qi", 50000);
	set("max_qi", 50000);
	set("qi", 50000);
	set("max_jing", 50000);
	set("jing", 50000);
	set("max_jingli", 50000);
    set("eff_jingli", 50000);
 	set("jingli", 50000);
	set("qi_no",1);
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
	NPCS_D->set_from_me(ob, me, 250);
	return 1;
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp;
int na,nb,nc,nd;
	if (objectp(killer = query_last_damage_from()))
	{
	exp=150000+random(1500);
	na=100000+random(1000);
	nb=50000+random(1000);
	nc=30000+random(1000);
	killer->add("experience",na);
	killer->add("potential",nb);
	killer->add("magic_points",nc);	
		
	tell_object(killer,"你杀死"+name()+"，获得"+exp+"点经验，"+na+"点实战，"+nb+"点潜能，"+nc+"点灵慧。\n");	}
	CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在十三皇陵中击杀了魂帝，获得了"+nc+"点灵慧。\n");									
	
	switch (random(10))
	{
		case 0 : 
		case 5 :
		case 9 :
			new(id)->move(killer);
			
CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在十三皇陵中获得了"+id->short()+"。\n");									
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
