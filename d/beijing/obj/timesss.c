
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
	set_name(HIY "timesss" NOR, ({ "timesss", "tiemsss" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "timesss。\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 10000000000000);
	//	set("yuanbao", 10000000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->apply_condition("timesss",10000);
	write(HIY "效果开始。"NOR"\n");
    add_amount(-1);
    return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
