// guanjia.c 财主管家

inherit NPC;

void create()
{
	set_name("管家", ({ "guan jia", "guan" }));
	set("gender", "男性");
	set("age", 65);

	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", -1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
	

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
