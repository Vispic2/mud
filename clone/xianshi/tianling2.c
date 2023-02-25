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
	set_name(HIY"玄灵丹[经验]"NOR, ({"xuanling dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 500);
        set("max_buy",1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 10000);
		set("long","这是一颗玄灵丹，可以增加一小时的三倍时间，不可叠加效果。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;

	me->apply_condition("db_exp2", 360+me->query_condition("db_exp2"));

	write(YEL"你服下一颗"HIY"玄灵丹"YEL"，顿觉神清气爽、思维敏捷!"NOR"\n");
	add_amount(-1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
