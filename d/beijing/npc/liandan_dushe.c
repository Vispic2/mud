#include <ansi.h>

inherit SNAKE;

void create()
{
	set_name("毒蛇", ({ "du she", "du", "she"}));
	set("long",     "一支昂首吐信的毒蛇，正虎视眈眈地盯著你。\n");
	set("race", "野兽");
	set("age", 3);
	set("attitude", "peaceful");
	set("max_ging", 40);
	set("max_qi", 40);
	set("str", 10);
	set("cor", 30);
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("snake_poison", ([
		"level"   : 80,
		"remain"  : 20,
		"maximum" : 20,
		"perhit"  : 10,
		"supply"  : 1,
	]));

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	set("combat_exp", 8000);

	setup();
}

void init()
{
	object ob;

	::init();

	if (interactive(ob = this_player()))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
