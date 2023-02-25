// jingqi.c
// 精+、气+

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(WHT "精气丸" NOR, ({ "jingqi wan", "wan" }));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一粒白色的药丸，似乎对身体状态有所补益。\n");
		set("base_unit", "粒");
		set("base_value", 1000);
		set("base_weight", 70);
		set("only_do_effect", 1);
		set("mixture", ([
			"herb" : ([ "chuanwu"  : 1,
				    "honghua"  : 1,
				    "dangui"   : 1,
				    "chenpi"   : 1,
				    "moyao"    : 1,
				    "shengdi"  : 1,
				    "yjhua"    : 1, ]),
			"neili" : 150,
			"jing"  : 40,
			"time"  : 5,
			"min_level" : 40,
			"medical" : 100,
		]));
	}
	setup();
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/jingqi") < 25)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();
	if (my["eff_jing"] == my["max_jing"] &&
	    my["eff_qi"] == my["max_qi"])
	{
		write("你现在并没有受伤，不必服用" + name() + "。\n");
		return 1;
	}

	me->set_temp("last_eat/jingqi", time());

	message_vision(WHT "$N" WHT "把" + name() +
		       WHT "咕咚一声吞下了肚，立刻气色看起来好多了。"NOR"\n", me);

	me->receive_curing("jing", 100);
	me->receive_curing("qi", 100);
	me->receive_heal("jing", 100);
	me->receive_heal("qi", 100);

	me->start_busy(1);

	add_amount(-1);
	if (query_amount() < 1)
		destruct(this_object());

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
