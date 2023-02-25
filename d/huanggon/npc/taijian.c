
inherit NPC;

void create()
{
	set_name("太监", ({ "tai jian", "tai" ,"jian"}));
	set("gender", "无性");
	set("age", 15+random(60));

	set("combat_exp", 5000);
	set("shen_type", 0);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	add_money("silver", random(10));
	carry_object("/d/city/obj/cloth")->wear();
}
	

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
