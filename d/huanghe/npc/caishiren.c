// caishiren.c

inherit NPC;


void create()
{
	set_name("采石人", ({ "caishi ren","ren" }));
	set("gender", "男性");
	set("age", 22);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "这是一个精壮汉子。\n");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	setup();
	carry_object(__DIR__"obj/tieqiao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
