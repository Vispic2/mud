// tufei.c

inherit NPC;
#include <ansi.h>

//可爆出物品列表
string *random_ob = ({
  "/clone/vip/putao",
  "/clone/vip/dan_chongmai1",
});

void create()
{	int lvl,q,j;
	lvl = 320 + random(180);
	q = 5000 + random(3001);
	j = 5000;
	set_name(RED"阴魂"NOR, ({ "qiu tu"}) );
	set("gender", "男性");
	set("age", 45);
	set("long", "邪气冲天的亡魂。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 35);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi",q );
	set("max_qi", q);
	set("jing", j);
	set("max_jing", j);
	set("neili", 8000);
	set("max_neili", 8000);
	
	set_skill("force", lvl);
	set_skill("taiji-shengong", lvl);
    set_skill("parry", lvl);
    set_skill("dodge", lvl);
    set_skill("tiyunzong", lvl);
    set_skill("sword", lvl);
    set_skill("taiji-jian", lvl);
    set_skill("hand", lvl);
    set_skill("paiyun-shou", lvl);
    set_skill("unarmed", lvl);
    set_skill("taiji-quan", lvl);

    map_skill("parry", "taiji-jian");
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("sword", "taiji-jian");
    map_skill("hand", "paiyun-shou");
    map_skill("unarmed", "taiji-quan");

    prepare_skill("hand", "paiyun-shou");
    prepare_skill("unarmed", "taiji-quan");

    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
            (: exert_function, "powerup" :),
            (: perform_action, "sword.lian" :),
            (: perform_action, "sword.chan" :),
            (: perform_action, "sword.sui" :),
            (: perform_action, "unarmed.zhen" :),
            (: exert_function, "recover" :),
                     }) );
		
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 5);
}

int accept_fight(object me)
{
	command("say 我在这被关了这么久，可终于见到一个活人了！\n");
	kill_ob(me);
	return 1;
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp,pot,mot;

	if (objectp(killer = query_last_damage_from()))
	{
	    exp=25+random(25);
	    pot=25+random(25);
		killer->add("combat_exp",exp);
		killer->add("potential",pot);
		tell_object(killer,"你杀死"+name()+"，获得"+exp+"点经验，"+pot+"点潜能。\n");
	}
	
	switch (random(15))
	{
			case 5 :
			case 14 :
			new(id)->move(killer);
CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在《镇魂妖塔》获得了"+id->short()+"。");									
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
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
