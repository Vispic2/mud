//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
//inherit NPC;
inherit CLASS_D("generate") + "/chineses";
string *random_ob = ({
    "/clone/shizhe/putao",
    "/clone/shizhe/dan_chongmai1",
    "/clone/shizhe/tianling",    
    "/clone/shizhe/jinsha",
    "/clone/shizhe/book_wuliang",
    "/clone/shizhe/book_tianfu",
});

void create()
{
   object ob = this_player();
	::create();
	set_name(HIY"金国密探"NOR,({"tan zi"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_neili", 2000);
	set("neili", 2000);
	set("eff_qi", 2000);
	set("max_qi", 2000);
	set("qi", 2000);
	set("max_jing", 2000);
	set("jing", 2000);
	set("max_jingli", 2000);
    set("eff_jingli", 2000);
 	set("jingli", 2000);
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
	NPCS_D->set_from_me(ob, me, 150);
	return 1;
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exps,pot,d1;

	if (objectp(killer = query_last_damage_from()))
	{
     	d1 = new("/clone/money/gold");
	    d1->set_amount(10);	   
	    d1->move(killer);
		tell_object(killer,"你杀死"+name()+"，你获得了十两黄金。\n");
	}
	
	switch (random(10))
	{
		case 0 : 
		case 5 :
		case 9 :
			new(id)->move(killer);
			message("channel:chat",HIY"伏击金兵："+HIG+killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。\n",users());	
//>CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。");									
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
