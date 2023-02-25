// mixian.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("过桥米线", ({"guoqiao mixian", "mixian"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一碗热气腾腾的油浸的米粉，正是大理名菜过桥米线。\n");
		set("unit", "碗");
		set("value", 80);
		set("food_remaining", 10);
		set("food_supply", 20);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
