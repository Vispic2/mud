// mengzi.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "孟子[VIP版]" NOR, ({ "mengzi books", "shus" }));
	set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", "这本书记载了当年孟子许多言行哲论，是儒家经典书籍。注：可以读到500级，需要150级基础。\n");
		set("value", 1);	
        set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("material", "paper");
		set("skill", ([
			"name": "literate",    // name of the skill
			"jing_cost":   100,    // jing cost every time study this
			"difficulty":   30,    // the base int to learn this skill
			"max_skill":   500,    // the maximum level you can learn to
			"min_skill":   150,    // minimun level required
		]));
	}
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
