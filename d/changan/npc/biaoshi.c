//biaoshi.c

inherit NPC;

void create()
{
	string *surname=({"赵","钱","孙","李","周","吴","郑","王",});
	set_name(surname[random(sizeof(surname))]+"镖师", ({ "biaoshi", "biao"}) );
	set("gender", "男性" );
	set("age", 25);
	set("str", 45);
	set("cor", 50);
	set("cps", 35);
	set("int", 20);
	set("per", 20);
	set("kar", 15);
	set("long", "一位训练有素的镖师。\n");
	set("combat_exp", 50000);
	set("attitude", "heroism");
	set_skill("parry", 90);
	set_skill("dodge", 100);
	
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
	add_money("silver",20);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
