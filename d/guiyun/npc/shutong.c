// shutong.c

inherit NPC;

void create()
{
	set_name("书童", ({ "shu tong", "tong" }));
	set("gender", "男性");
	set("age", 35);
	set("long", "他是庄主的随身书童，平素看管藏书。\n");
	set("combat_exp", 10000);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set("shen_type", -1);
	setup();

	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
