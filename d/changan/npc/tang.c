//tang.c

inherit NPC;

void create()
{
	set_name("趟子手", ({ "tang" }));
	set("gender", "男性" );
	set("age", 24);
	set("long", "一位训练有素的趟子手。\n");
	set("combat_exp", 40000);
	set("attitude", "friendly");
	set_skill("unarmed", 80);
	set_skill("dodge", 100);

	setup();
	add_money("silver", 10);
	carry_object(__DIR__"obj/jinzhuang")->wear();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
