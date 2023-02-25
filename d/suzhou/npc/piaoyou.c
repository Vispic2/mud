// piaoyou.c

inherit NPC;

void create()
{
	set_name("票友", ({ "piao you", "piao", "you" }));
	set("gender", "男性");
	set("age", 15+random(70));

	set("combat_exp", 5000+random(10000));
	set_skill("unarmed", 10+random(50));
	set_skill("force", 10+random(50));
	set_skill("dodge", 10+random(50));
	set_temp("apply/attack", 5+random(50));
	set_temp("apply/defense", 5+random(50));
	set("shen_type", 0);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", random(20));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
