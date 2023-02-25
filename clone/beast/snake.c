//snake.c

inherit SNAKE;

void create()
{
	set_name("黑冠巨蟒", ({ "black snake", "she" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一只庞然大物，它眼中喷火,好象要一口把你吞下。\n");
	set("attitude", "aggressive");
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 500);
	set("max_jing", 500);
	set("str", 86);
	set("con", 80);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1000000);

	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence",80);

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
