// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(HIG "清心定神散" NOR, ({"qingxin san", "san"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一包淡绿色的粉末，具有非常不错的镇定效果。\n");
		set("base_unit", "包");
		set("base_value", 1500);
		set("base_weight", 60);
		set("only_do_effect", 1);
		set("mixture", ([
			"herb" : ([ "chuanwu"  : 1,
				    "xuejie"   : 1,
				    "yjhua"    : 1,
				    "xiongdan" : 1,
				    "shancha"  : 1,
				    "gsliu"    : 1,
				    "zzfen"    : 1, ]),
			"neili" : 100,
			"jing"  : 50,
			"time"  : 3,
			"min_level" : 80,
			"medical" : 100,
		]));
	}
	setup();
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/qingxin") < 20)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();
	if (my["eff_jing"] == my["max_jing"])
	{
		write("你现在精神状态很好，无需服用" + name() + "。\n");
		return 1;
	}

	me->set_temp("last_eat/qingxin", time());

	message_vision(HIG "$N" HIG "一张嘴，吞下了" + name() +
		       HIG "，看上去精神好多了。"NOR"\n", me);

	me->receive_curing("jing", 150);
	me->receive_heal("jing", 150);

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
