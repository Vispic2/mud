//miantang.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("面汤", ({"mian tang", "miantang", "mian"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long", "一碗热气腾腾的面汤。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 10);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
