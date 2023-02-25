// blade-book.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIR"锦盒"NOR,({ "jinhe","he"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long","这是一个锦盒。\n");
		set("value", 0);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
                        "name":         "qianzhu-wandushou",      //name of the skill
                        "exp_required": 100000 ,        //minimum combat experience required
			"jing_cost":    30+random(100),// jing cost every time study this
			"difficulty":	30,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	250            // the maximum level you can learn
		]) );
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
