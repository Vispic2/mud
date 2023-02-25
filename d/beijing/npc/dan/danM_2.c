#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(WHT "龟苓丹" NOR, ({"guiling dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "粒");
		set("base_value", 0);
		set("only_do_effect", 2);
	}
	setup();
	set_amount(1);
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/dan(M)") < 400)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();

	me->set_temp("last_eat/dan(M)", time());

	if (me->improve_neili(2))
		message_vision(WHT "$N" WHT "吃下一粒龟苓丹，感到内力又雄厚"
			       "了一些。"NOR"\n", me);
	else
		message_vision(YEL "$N" YEL "吃了一粒龟苓丹，打了一个饱嗝。\n"
			       NOR, me);

	me->start_busy(6);

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
