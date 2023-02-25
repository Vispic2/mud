// dog.c

inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只浑身脏兮兮的野狗。\n");
	
	set("str", 32);
	set("dex", 36);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"野狗用鼻子闻了闻你的脚。\n",
		"野狗在你的脚边挨挨擦擦的，想讨东西吃。\n",
		"野狗对著你摇了摇尾巴。\n",
		"野狗用後腿抓了抓自己的耳朵。\n" }) );
		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "高兴地汪汪叫了起来。\n", environment());
		return 1;
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
