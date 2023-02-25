//xiangke.c

inherit NPC;

void create()
{
	set_name("香客", ({"xiang ke"}));
	set("gender", "男性");
	set("attitude", "peaceful");
	set("age", 20+random(10));
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("per", 30);
	set("max_qi", 600);
	set("max_jing", 400);
	set("neili", 400);
	set("jiali", 10);
	set_skill("force", 20+random(20));
	set_skill("unarmed", 20+random(20));
	set_skill("dodge", 20+random(20));
	set_skill("parry", 20+random(40));

	setup();
	carry_object(__DIR__"obj/changpao")->wear();
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
