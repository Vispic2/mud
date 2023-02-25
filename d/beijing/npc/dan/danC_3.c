#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(CYN"锁泉丹"NOR, ({"suoquan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "粒");
		set("base_value", 70);
		set("only_do_effect", 1);
	}
	setup();
	set_amount(1);
}

int do_effect(object me)
{
	mapping my;
	int jl, mj;

	if (time() - me->query_temp("last_eat/dan(C)") < 180)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();
	jl = (int)me->query("jingli") + 220;
	mj = (int)me->query("max_jingli") * 2;

	if (jl > mj)
	{
		write("你现在精力修为无需服用" + name() + "。\n");
		return 1;
	}

	me->set_temp("last_eat/dan(C)", time());

	message_vision(CYN "$N吃下一粒锁泉丹，精神随之一震，精力有所提高。"NOR"\n", me);
	me->add("jingli", 220);

	me->start_busy(3);

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
