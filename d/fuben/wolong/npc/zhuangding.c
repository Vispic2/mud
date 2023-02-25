// tufei.c

inherit NPC;
//#include <fb_skill.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name("庄丁", ({ "zhuang ding", "zhuangding" }) );
	set("gender", "男性");
	set("age", 30);
	set("long", "这家伙精神抖擞，满怀警惕的盯着靠近大门的陌生人。\n");

	set("combat_exp", 100000+random(300000));
	
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_basic();
	setup();

	add_money("silver", 50+random(50));
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();
	
	if (userp(me)) {
		command("say 此乃私家庄园，不得进入！\n");
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 20);
		if (!random(3))
			ob->do_clone(me, 20);
		//kill_ob(me);
		//me->kill_ob(this_object());
	}
}

void die()
{
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		exp = this_object()->query_skill("force",1)*2;
			if(killer->query("djexp")){
		exp=exp*3;
		}
		killer->add("combat_exp",exp);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点经验。"ZJBR+ZJBR"\n");
	}
	
	::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
