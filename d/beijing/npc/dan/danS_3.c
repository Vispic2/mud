#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(WHT"玄武"NOR+HIY"神农丹"NOR, ({"xuanwu dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "增加200点经验和潜能，并补满精力和内力，冷却30秒。\n");
		set("base_unit", "粒");
		set("no_drop", "这样东西不能离开你。\n");
		set("no_sell", "这样东西不能离开你。\n");
		set("no_put", "这样东西不能放在那儿。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("no_steal", "这样东西不能离开那儿。\n");
		set("no_beg", "这样东西不能离开那儿。\n");
		set("base_value", 0);
		set("only_do_effect", 1);
	}
	setup();
	set_amount(1);
}

int do_effect(object me)
{
	mapping my;

	if (time() - me->query_temp("last_eat/dan(S)") < 30)
	{
		write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
		return 1;
	}

	my = me->query_entire_dbase();

	me->set_temp("last_eat/dan(S)", time());

	message_sort(WHT "$N" WHT "吃下一颗$n" WHT "，只觉"
		     "全身筋脉逆流而上，内力源源不断的涌入"
		     "丹田，说不出的舒服受用。顿时感到灵台"
		     "处如湖面一般平静，以往所学的武学知识"
		     "一一涌向心头，在灵台处交融贯通。$N" WHT
		     "感到的经验和潜能有了一定的进展。"NOR"\n", me, this_object());
	me->set("jingli", me->query("max_jingli"));
	me->set("neili", me->query("max_neili"));
	me->add("combat_exp", 200);
	me->add("potential", 200);

	me->start_busy(2);

	add_amount(-1);
	if (query_amount() < 1)
		destruct(this_object());

	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
