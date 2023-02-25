inherit NPC;

void create()
{
	set_name("趟子手", ({ "tang zi", "zi", "tang" }) );
	set("gender", "男性" );
	set("age", 25);
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "peaceful");
	set_skill("dodge",20);
	set_skill("unarmed",20);
	set("chat_chance", 1);

	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("coin", 10);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
