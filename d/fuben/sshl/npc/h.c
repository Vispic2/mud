// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name(HIY"魂帝"NOR, ({ "hun di", "hundi" }) );	
	set("age", 100);
	set("combat_exp", 1000000+random(300000));	
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_basic();
	setup();

	add_money("gold",1+random(4));
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();
	
	if (userp(me))
	 {
		//command(HIR"say 敢独闯十三黄陵你是不想活了！！！\n"NOR);		
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 80);
		if (!random(2))
			ob->do_clone(me, 1000);
		//kill_ob(me);
		//me->kill_ob(this_object());
	}
}

void die()
{
	object killer,ob;
	int exp,pot,i,me;

	if (objectp(killer = query_last_damage_from()))
	{
		exp = this_object()->query_skill("force",1)*10;
		killer->add("combat_exp",exp);
		pot = this_object()->query_skill("force",1)*10;
		killer->add("potential",pot);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点经验，获得"+pot+"点潜能。"ZJBR+ZJBR"\n");
        killer->set("l",0);        
		//killer->add("magic_points",500+random(500));
		//CHANNEL_D->do_channel( this_object(), "rumor","恭喜"+me->query("name")+"战胜了魂帝，获得了灵慧！");
		
i=random(10);
if (i==5)
{
i = new("/clone/shizhe/putao1");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
if (i==3)
{
i = new("/clone/shizhe/putao");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
		
if (i==9)
{
i = new("/clone/shizhe/ling_sshl");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
//by寒江雪		qq：2046889157
i=random(6);
if(i==3)
{
i = new("clone/shizhe/dan_neili");
i=move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}

if(i==5)
{
i = new("clone/shizhe/dan_xiaohuan");
i=move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过"HIY"十三黄陵副本"NOR"，获得了一"+i->query("unit")+i->name()+HIM"。");
}
	}
	
	::die();
}
int accept_kill(object me)
{
		if (me->query("l") < 4)
	{
		message_vision("先去击杀四只厉魂再来挑战我吧。\n",
			       this_object(), me);
		//me->unconcious();
		return -1;
	}
	command("sigh");
	command("say 很好！受死吧！");
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
