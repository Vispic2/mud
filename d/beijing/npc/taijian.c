inherit NPC;

void create()
{
	set_name("太监", ({ "tai jian", "tai", "jian" }) );
	set("gender", "无性" );
	set("age", 32);

	set("shen_type", 1);
	set("combat_exp", 1000);
	set("attitude", "peaceful");

	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
