// silver.c
#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(HIW"白银"NOR, ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "白花花的银子，人见人爱的银子。\n");
		set("unit", "两");
		set("base_value", 100);
		set("base_unit", "两");
		set("base_weight", 1);
	}
	set_amount(1);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
