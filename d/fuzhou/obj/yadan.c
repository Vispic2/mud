// yadan.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("臭鸭蛋", ({"chou yadan", "yadan", "egg"}));
	set_weight(70);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "臭鸭蛋闻着臭，吃着香。\n");
		set("unit", "颗");
		set("value", 80);
		set("food_remaining", 1);
		set("food_supply", 80);
	}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
