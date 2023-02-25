//随从任务
#include <ansi.h>
inherit CLASS_D("generate") + "/chineses";
#include "/cmds/usr/props.h"
void create()
{
	::create();
	set_name("随从任务", ({ "suicong rw" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "这是随从专用的任务npc。\n");
	set("min_exp", 1000);
	set("str", 30);
	set("con", 30);
	set("dex", 30);
	set("int", 30);

	set("max_qi", 5000+random(5000));
	set("eff_qi", 5000+random(5000));
	set("qi", 5000+random(5000));
	set("max_jing", 5000+random(5000));
	set("jing", 5000+random(5000));
	set("neili", 5000+random(5000));
	set("max_neili", 5000+random(5000));
	set("jiali", 50+random(50));
	set("shen_type", 0);
	set("combat_exp", 100000+random(100000));
	set_skill("force",   100+random(100)); 
	set_skill("unarmed", 100+random(100));
	set_skill("dodge",   100+random(100));
	set_skill("parry",   100+random(100));
        
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
	object me;
	int kill,room;
    if (me->query("sc") < 1)
	return notify_fail("你不打随从专属任务。\n");
	write("攻击成功\n");
	return 1;
}

void die()
{
	int exp,pot;
	string id = props[random(sizeof(props))];//随机物品
    object killer=this_player();    
    if (objectp(killer = query_last_damage_from())){	
	exp=10+random(10);
	pot=5+random(5);
	killer->add("combat_pet",exp*10);
	killer->add("potential_pet",pot*10);		
	killer->add("eykillsc",1);
	tell_object(killer,"你杀死"+name()+"，获得了("+exp*10+")点经验，("+pot*10+")潜能，请不要恶意击杀随从专属任务。\n");		
	}		
	switch (random(100))
	{
		case 50 :		
		new(id)->move(killer);
        CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在任务中获得了"+id->short()+"。");									
		break;
	}	
    	::die();
}

void unconcious()
{
	die();
}
void random_move()
{        
   if(time()-query_temp("born_time") > 300){                       
   destruct(this_object());       
   return;       
  }
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
