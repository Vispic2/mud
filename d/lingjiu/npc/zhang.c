//zhang.c
inherit NPC;

void create()
{
	set_name("獐", ({ "zhang" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一头可爱的獐，它的血是大补之物。\n");
	set("attitude", "peaceful");
 
	set("str", 30);
	set("cor", 26);

	set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
	set("verbs", ({ "bite" }) );
 
	set("combat_exp", 3000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);

	setup();
}

void die()
{
	message_vision("$N两腿一蹬，$N死了。\n", this_object());
	destruct(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
