#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(HIR"火麒丹"NOR, ({"huoqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "补充3000点内力，冷却30秒。\n");
		set("base_unit", "粒");
		set("base_value", 80);
		set("only_do_effect", 1);
	}
	setup();
	set_amount(1);
}

int do_effect(object me)
{
	mapping my;
	int nl, mn;

	if (time() - me->query_temp("last_eat/dan(D)") < 30)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();
	nl = (int)me->query("neili") + 3000;
	mn = (int)me->query("max_neili") * 2;

	if (nl > mn)
	{
		write("你现在内力修为无需服用" + name() + "。\n");
		return 1;
	}

	me->set_temp("last_eat/dan(D)", time());

	message_vision(HIR "$N吃下一粒火麒丹，感到内力有所补充。"NOR"\n", me);
	me->add("neili", 3000);

	me->start_busy(2);

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
