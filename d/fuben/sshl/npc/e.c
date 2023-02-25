// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name(MAG"恶魂"NOR, ({ "e hun", "ehun" }) );	
	set("age", 30);
	set("combat_exp", 100000+random(300000));	
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_basic();
	setup();

	add_money("gold",1);
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();
	
	if (playerp(me))
	 {
		//command(HIR"say 敢独闯十三黄陵你是不想活了！！！\n"NOR);		
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 50);
		if (!random(3))
			ob->do_clone(me, 60);
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
		exp = this_object()->query_skill("force",1)*5;
		killer->add("combat_exp",exp);
		pot = this_object()->query_skill("force",1)*5;
		killer->add("potential",pot);
		tell_object(killer,"你杀死"+name()+"，获得"+exp+"点经验，获得"+pot+"点潜能。\n");
i=random(10);
if (i==5)
{
i = new("/clone/shizhe/book_wuliang");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
if (i==9)
{
i = new("/clone/shizhe/putao");
i->move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}
		
i=random(10);
if(i==4)
{
i = new("clone/shizhe/dan_neili");
i=move(me);
CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"通过十三黄陵副本，获得了一"+i->query("unit")+i->name()+HIM"。");
}

if(i==8)
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
