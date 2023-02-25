// yingying.c 崔莺莺

inherit NPC;

void create()
{
	set_name("崔莺莺", ({ "cui yingying", "cui", "ying" }));
	set("long", "她长得极美，尤其是那对眼睛，媚得直可以勾人魂魄。\n");
	set("title", "财主女儿");
	set("gender", "女性");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}
	

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
