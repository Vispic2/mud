// xianhe.c

inherit NPC;
#include <ansi.h>;
void create()
{
	set_name(HIR"丹"NOR"顶鹤", ({ "danding he", "he"}));
	set("race", "野兽");
	set("age", 3);
	set("long", "一只全身洁白的丹顶鹤，看来是修了翅膀，没法高飞了。\n");
	set("attitude", "peaceful");

	set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 300);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 7);
	set_temp("apply/armor", 7);

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
