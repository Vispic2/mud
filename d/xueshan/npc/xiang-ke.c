// xiang-ke.c 进香客

inherit NPC;

void create()
{
	int value;

	value = random(10);

	set_name("进香客", ({ "jinxiang ke", "ke", "guest" }));
	set("gender", "男性");
	set("age", 14 + value * 3 );

	set("combat_exp", 500 + 5 * value);
	set("shen_type", 0);
	setup();
	add_money("silver", 1 + value);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
