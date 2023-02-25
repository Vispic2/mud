// birdie.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鸟肉", ({"niao", "bird"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块喷香的鸟肉，真让人嘴馋。\n");
		set("unit", "块");
		set("value", 180);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
