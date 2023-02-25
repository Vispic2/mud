// banjiu.c

inherit NPC;

void create()
{
	set_name("斑鸠", ({ "ban jiu"}));
	set("race", "野兽");
	set("age", 3);
	set("long", "一只小斑鸠，在田地间跳上跳下。\n");
	set("attitude", "peaceful");

	set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
