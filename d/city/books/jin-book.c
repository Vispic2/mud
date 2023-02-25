// parry-book.c

inherit ITEM;

void create()
{
	set_name( "锐金决秘籍",({ "ruijin book"}));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本失传已久的高武秘籍。\n");
		set("value", 1500);
		set("no_sell",1);
	   set("no_give",1);
	   set("no_drop",1);
		set("material", "paper");
		set("skill", ([
			"name":	 "ruijin-jue",      //name of the skill
			"exp_required": 1 ,	   //minimum combat experience required
			"jing_cost":    100,// jing cost every time study this
			"difficulty":	1000,	   // the base int to learn this skill
			"min_skill":	0,	    // the minimum level you can learn
			"max_skill":	9999	    // the maximum level you can learn
		]) );
	}
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
