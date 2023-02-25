// guigu.c 鬼谷神算

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT "鬼谷神算" NOR, ({ "guigu book", "book", "shu" }));
	set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", HIW"传说是当年鬼谷子所著的奇书。注：可以读到300级，需要150级基础可以读。\n"NOR);
		set("value", 100);
		set("no_sell", "这...这值什么钱？\n");
		set("material", "silk");
		set("skill", ([
			"name": "mathematics", // name of the skill
			"jing_cost":   150,    // jing cost every time study this
			"difficulty":   40,    // the base int to learn this skill
			"max_skill":   300,    // the maximum level you can learn to
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
