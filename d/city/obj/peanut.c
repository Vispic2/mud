// peanut.c 花生

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("五香花生", ({"huasheng", "peanut"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟香喷喷的花生米。\n");
		set("unit", "碟");
		set("value", 30);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
