// yuanwai.c
inherit NPC;

void create()
{
	set_name("侯员外", ({ "hou yuanwai", "hou" }));
	set("long",
		"侯员外据说是这长安镇上的首富，谁也不知道他到底有多少\n"
		"家财。他大约五十出头，长的富富态态。\n");
	set("gender", "男性");
	set("age", 52);

	set("combat_exp", 12000);
	set_skill("unarmed", 45);
	set_skill("force", 42);
	set_skill("dodge", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/defense", 42);

	setup();
	carry_object(__DIR__"obj/jinduan")->wear();
	add_money("silver", 50);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
