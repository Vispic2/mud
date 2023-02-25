// little_bee.c

inherit NPC;

void create()
{
	set_name("小蜜蜂", ({ "little bee", "bee"}) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只飞来飞去的小蜜蜂。\n");
	
	set("str", 30);
	set("dex", 40);

	set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
	set("verbs", ({ "bite", "poke" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	"小蜜蜂嗡嗡嗡飞过来，在你头上转了一圈，有飞走了。\n",
	 }) );

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
