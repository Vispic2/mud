//miantiao1.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("刀削面", ({"daoxiao mian", "miantiao", "mian"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long", "一碗热气腾腾的刀削面。\n");
		set("unit", "碗");
	      set("icon", "00820");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 35);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
