// rice.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(YEL"黄米饭"NOR, ({ "rice", "mi fan" }) );
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗香喷喷的黄米饭。\n");
		set("unit", "碗");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
		set("material", "rice");
	}
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
