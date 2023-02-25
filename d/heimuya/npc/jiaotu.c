// jiaotu.c 日月神教教徒

inherit NPC;

void create()
{
	int age;
	age = 20 + random(10);
	set_name("日月神教教徒", ({ "jiao tu", "tu" }));
	set("gender", "男性");
	set("age", age);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);	
	set("apply/attack", 20);
	set("apply/defense", 20);
	set("apply/damage", 5);
	set("combat_exp", 550 + age*10);
	set("shen_type", -1);
	setup();
	add_money("silver", 10);
}	
void init()
{
	object ob,me,what;
	::init();
	ob = this_player();
	me = this_object();
	if( interactive(ob) && ! is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment()) return;

	switch (random(1))
	{
	case 0:
		command("say 日月神教，日出东方，唯我不败。\n");
		break;
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
