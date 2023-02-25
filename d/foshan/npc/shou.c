// shou.c

inherit NPC;

void create()
{
	set_name("瘦商人", ({ "shou shangren", "shou" }));
	set("gender", "男性");
	set("age", 43);
	set("long", "他瘦兮兮的，一脸穷苦相。\n");
	set("combat_exp", 2000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", 0);
	setup();

	add_money("silver",3);
	carry_object(__DIR__"obj/magcloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
