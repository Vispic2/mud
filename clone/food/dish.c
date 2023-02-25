// dish.c 菜肴

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("菜肴", ({ "dish" }));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "份");
		set("food_remaining", 4);
		set("food_supply", 15);
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
