// kid.c

inherit NPC;

void create()
{
	set_name("小孩",({ "kid" }) );
	set("gender", "男性" );
	set("age", 7);
	set("long", "这是个维吾尔族小孩子\n");
	set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/wcloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
