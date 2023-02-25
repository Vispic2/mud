// npc: /d/xingxiu/npc/caiyaoren.c
// Jay 3/18/96

inherit NPC;

void create()
{
	set_name("采药人", ({ "caiyao ren", "caiyao", "ren" }));
	set("gender", "男性");
	set("age", 30 + random(10));

	set("long", "一个辛苦工作的采药人。\n");
	set("attitude", "friendly");

	set("combat_exp", 1000);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("hammer", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	setup();
	carry_object("/d/xingxiu/obj/xuelian");
	add_money("coin", 50);
	carry_object("/d/xingxiu/obj/yaochu")->wield();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
