inherit NPC;

void create()
{
	set_name("掌柜", ({ "zhanggui", "gui" }));
	set("gender", "男性");
	set("age", 45);

	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", 1);

	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("silver",20);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
