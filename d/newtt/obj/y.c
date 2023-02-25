// liapo.c 李阿婆

inherit NPC;


void create()
{
	set_name("丫鬟", ({ "yhuan"}));
	set("str", 18);
	set("gender", "女性");
	set("age", 10);
	set("long", "这是一个丫鬟。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");


	setup();
	carry_object("/clone/misc/cloth")->wear();

	
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
