// liang.c 梁喜禄

inherit NPC;

void create()
{
	set_name("梁喜禄", ({"liang xilu", "liang", "boss"}));
	set("title", "货栈老板");
	set("gender", "男性");
	set("age", 35);
	set("kee", 350); 
	set("max_kee", 350);
	set("sen", 200);
	set("max_sen", 200);	
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 10);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	setup();
	carry_object(__DIR__"obj/choupao")->wear();
	add_money("silver", 1);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
