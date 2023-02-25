
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIG"糊涂丹"NOR, ({"hutu dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIG"可以遗忘所有读书写字!！注:谨慎使用!!\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("yuanbao", 10); 	
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");	
	me->delete_skill("literate");
	tell_object(me,"你遗忘了读书写字。。。。\n");	
	add_amount(-1);
	me->save();
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
