// wolf.c
inherit NPC;

void create()
{
	set_name("野狼", ({ "wolf", "yelang", "lang" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只独行的野狼，半张着的大嘴里露着几颗獠牙。\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("limbs", ({ "狼头", "狼身", "前爪", "后抓", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 20000);
	set_temp("apply/attack", 2000);
	set_temp("apply/defense", 3000);
	set_temp("apply/armor", 800);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"野狼耷邋着尾巴，突然抬头，冲你发出一声凄厉的长嚎。\n",
		"野狼闪着绿幽幽的眼光冲你瞄了瞄，血盆巨口里答答滴着哈喇子。\n",
	}) );
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
