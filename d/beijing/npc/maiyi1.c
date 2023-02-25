inherit NPC;

void create()
{
	set_name("耍猴人", ({ "shuahou ren", "ren" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long",
	      "一个沿街耍猴的人。\n");
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
	set("chat_msg", ({
		 "耍猴人大声叫道：各位父老，快来瞧瞧。\n",
	}) );       

	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("silver", 10);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
