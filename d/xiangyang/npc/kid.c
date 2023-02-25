// kid.c

inherit NPC;

void create()
{
	set_name("小孩",({ "kid" }) );
	set("gender", "男性" );
	set("age", 7);
	set("long", "这是个襄阳城中贫民小孩，淘气得很。\n");
	set("combat_exp", 50);
//	set("shen", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
