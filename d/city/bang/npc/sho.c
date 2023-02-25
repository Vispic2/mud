#include <ansi.h>;
inherit "/kungfu/class/generate/chinese";

void create()
{
	string *fams;

	set_name("圣地守护者", ({"sho",}));
	set("gender", "男性");
	set("age", 20 + random(20));
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("killkys",1);
    set("max_qi", 1000000);
	set("eff_qi", 1000000);
	set("qi", 1000000);
	set("max_neili", 1000000);
	set("neili", 1000000);
	set("max_jing", 1000000);
	set("eff_jing", 1000000);
	set("jing", 1000000);
	set("combat_exp", 1000000);
	set("bangzhansho",1);
	set("attitude", "peaceful");
	setup();
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}
int accept_kill(object me)
{
	string short;
	if(!(short=me->query("banghui/name")))
	{
	tell_object(me,"没有帮派你过来干嘛？\n");	
	return 0;
	}
	if(this_object()->query("bangpai")==short)
	{
	tell_object(me,"自己的帮派守护者也要击杀？\n");
	return 0;
	}
	return accept_hit(me);
}
int accept_fight(object me)
{
	tell_object(me,"帮派守护者不能切磋！\n");
	return 0;
}
void init()
{
	object me = this_object();
	mapping smap = me->query_skills();
	int i;
	string *skills;
	int lvl;
    lvl=me->query("skilllvl");
	if(!lvl||lvl<1)
		lvl=500;
	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
	   me->set_skill(skills[i],lvl);
	}

	me->set("combat_exp",lvl*100000);
	me->set_temp("apply/damage",lvl*10);
	me->set_temp("apply/unarmed_damage",lvl*10);		
}

void die()
{
    string short;
	object killer;
	int qi,jing;
	object me=this_object();
	qi=me->query("max_qi");
	jing=me->query("max_jing");	
if (objectp(killer = query_last_damage_from()))
	{
	if(!(short=killer->query("banghui/name")))
		{
          this_object()->set("qi",qi);
          this_object()->set("eff_qi",qi);
          this_object()->set("jing",jing);
          this_object()->set("eff_jing",jing);
    CHANNEL_D->do_channel(me, "chat", HIY""+killer->query("name")+"击杀了守护者，但由于没有帮派，守护者复活！"NOR"");
	shout(HIY""+killer->query("name")+"击杀了守护者，但由于没有帮派，守护者复活！"NOR"\n" );
		  return;
		}
	else
	{
	environment(me)->set("shendishohu",short);
	environment(me)->start();
    CHANNEL_D->do_channel(me, "chat", HIY""+killer->query("name")+"击杀了守护者，"+short+"帮派获得圣地守护权！"NOR"");
	shout(HIY""+killer->query("name")+"击杀了守护者，"+short+"帮派获得圣地守护权！"NOR"\n" );
	}
	}
	::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
