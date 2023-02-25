// hutaseng1.c
inherit NPC;

void create()
{
	set_name("护塔僧", ({ "huta seng","seng"}) );
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 33);
	set("shen_type", 1);
	set("str", 21);
	set("int", 21);
	set("con", 22);
	set("dex", 33);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 20);
	set("combat_exp", 80000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("tiannan-step", 80);
	set_skill("duanshi-xinfa", 70);

	map_skill("force", "duanshi-xinfa");
	map_skill("dodge", "tiannan-step");

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
