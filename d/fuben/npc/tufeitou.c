// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

//杀头领可爆出物品列表
string *random_ob = ({
    "/clone/vip/putao",
    "/clone/money/gold",
});

void create()
{
	set_name("土匪头领", ({ "tufei tou", "tufei", "tou","fei" }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set_basic();
	setup();

	add_money("gold", 1+random(3));
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();

	if (userp(me)) {
		command("say 你是谁！闯进山寨想干嘛？！\n");
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 10);
		if (!random(3))
			ob->do_clone(me, 10);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object ob;
	
	switch (random(10))
	{
		case 0 : 
		case 5 :
		case 9 :
			new(id)->move(this_object());
		break;
	}
	::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
