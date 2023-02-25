inherit NPC;

void create()
{
	set_name("老旦", ({ "lao dan", "lao", "dan" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
	      "一个在戏院唱戏的戏子。\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "peaceful");
	set_skill("dodge",20);
	set_skill("unarmed",20);
	
	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
	add_money("coin", 30);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
