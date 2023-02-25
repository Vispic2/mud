// zixia_book.c  紫霞秘芨
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"紫霞秘籍"NOR, ({ "zixia_book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("no_sell",1);
		set("long",
			"学紫霞神功。\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	 "zixia-shengong",       // name of the skill
			"exp_required": 100000,		 // minimum combat experience required
								// to learn this skill.
			"jing_cost" :   30,
			"difficulty":   30,		     // the base int to learn this skill
								// modify is gin_cost's (difficulty - int)*5%
			"max_skill":    119,		    // the maximum level you can learn
			"min_skill":    20		       // the maximum level you can learn
								// from this object.
		]) );
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
