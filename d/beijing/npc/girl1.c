inherit NPC;

void create()
{
	set_name("少女", ({ "shao nv", "nv" }) );
	set("gender", "女性" );
	set("age", 17);
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "peaceful");

	setup();
	carry_object("/d/beijing/npc/obj/nvcloth")->wear();
	add_money("silver", 2);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
