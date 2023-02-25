inherit NPC;

void create()
{
	set_name("茶客", ({ "cha ke", "cha", "ke" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long",
	      "一个在茶铺喝茶的人。\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "peaceful");
	set_skill("dodge",20);
	set_skill("unarmed",20);
	set("chat_chance", 1);
	set("chat_msg", ({
		"茶客低着头喝了口茶。\n",
	}) );       
	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("silver", 1);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
