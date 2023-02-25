inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("面馆伙计", ({ "mianguan huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18+random(20));
	set("long", "他是小面馆的伙计。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	setup();
	carry_object("/d/beijing/npc/obj/cloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
