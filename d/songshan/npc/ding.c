// ding.c
inherit NPC;

#include <ansi.h>

void create()
{
	set_name("丁勉", ({ "ding mian", "ding", "mian" }) );
	set("nickname", "托塔手");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 110000);
	set("shen_type", -1);

	set_skill("unarmed", 80);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("songshan-sword", 100);
	set_skill("lingxu-bu", 100);
	set_skill("songshan-xinfa", 80);

	map_skill("force", "songshan-xinfa");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "lingxu-bu");

	create_family("嵩山派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
