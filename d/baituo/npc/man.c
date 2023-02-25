// man.c

inherit NPC;

void create()
{
	set_name("农民", ({ "man" }) );
	set("gender", "男性" );
	set("age", 29);
	set("long", "一个很健壮的壮年农民。\n");
	set("shen_type", 1);
	set("combat_exp", 2000);
	set("str", 20);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
