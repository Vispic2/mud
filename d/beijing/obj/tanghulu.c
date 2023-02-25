#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"冰糖葫芦"NOR, ({ "bingtang hulu", "bingtang","hulu" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一串火红的冰糖葫芦\n");
		set("unit", "串");
		set("value", 50);
		set("food_remaining", 2);
		set("food_supply", 10);
	}
    setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
