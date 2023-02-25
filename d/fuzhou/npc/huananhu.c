// huananhu.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("华南虎", ({ "huanan hu", "tiger","hu" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", @LONG
一只矫健轻快的猛虎，雄伟极了。


    ("`-''-/").___..--''"`-.
     `@_ @ )   `-.  (  *  ).`-.__.`)
     (_Y_.)'  ._   )  `._ `. ``-..-'
      _..`--'_..-_/  /--'_.' ,'
    (il),-''  (li),'  ((!.-'


LONG);
	set("attitude", "aggressive");
	set("shen_type", -1);

	set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 30000);
	set("neili",800);
	set("jiali",100);
	set("max_neili",800);
	set("jingli",500);
	set("max_jingli",500);

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 300);
	set_temp("apply/armor", 100);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"老虎在浚巡，吓得你大气都不敢出。\n",
		"老虎仰天长啸，声震山谷，黄叶纷坠。\n",
	}) );
}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if (interactive(ob) && ! is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	if (environment()->query("no_fight"))
		return;

	if (! query_temp("owner"))
		kill_ob(ob);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
