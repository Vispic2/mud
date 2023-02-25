//bat.c 蝙蝠

inherit NPC;

void create()
{
	set_name("蝙蝠", ({"bianfu","bat"}) );
	set("race", "野兽");
	set("age", 8);
	set("long", "这是一只蝙蝠，正倒挂在洞顶。\n");

	set("str", 40);
	set("dex", 50);

	set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
	set("verbs", ({ "bite", "poke" }) );

	set_temp("apply/attack", 33);
	set_temp("apply/armor", 20);

	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	"蝙蝠扑扑地飞过来，在你头上转了一圈，又飞走了。\n",
	 }) );

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
