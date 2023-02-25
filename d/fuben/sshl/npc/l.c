// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name(HIR"厉魂"NOR, ({ "li hun", "lihun" }) );	
	set("age", 500);
	set("combat_exp", 1000000+random(30000));	
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_basic();
	setup();

	add_money("gold",1+random(2));
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
			ob->do_clone(me, 60);
		if (!random(3))
			ob->do_clone(me, 70);
		//kill_ob(me);
		//me->kill_ob(this_object());
	}
}

void die()
{
	object killer,ob;
	int exp,pot,me,i;

	if (objectp(killer = query_last_damage_from()))
	{
		exp = this_object()->query_skill("force",1)*7;
		killer->add("combat_exp",exp);
		pot = this_object()->query_skill("force",1)*7;
		killer->add("potential",pot);
killer->add("l",1);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点经验，获得"+pot+"点潜能。"ZJBR+ZJBR"\n");
  
i=random(20);
if (i==5)
{
i = new("/clone/shizhe/putao1");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
if (i==15)
{
i = new("/clone/shizhe/putao");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
		
if (i==20)
{
i = new("/clone/shizhe/ling_sshl");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
if (i==25)
{
i = new("/clone/shizhe/fushougao");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
//by寒江雪 QQ：2046889157		
i=random(8);
if(i==4)
{
i = new("clone/shizhe/dan_neili");
i=move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}

if(i==7)
{
i = new("clone/shizhe/dan_xiaohuan");
i=move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过"HIY"十三黄陵副本"NOR"，获得了一"+i->query("unit")+i->name()+HIM"。");
}
	}
	
	::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
