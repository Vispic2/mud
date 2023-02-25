// kaoya.c 烤鸭

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤鸭", ({"kaoya", "ya"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只肥得流油的北京烤鸭。\n");
		set("unit", "只");
		set("value", 1500);
		set("food_remaining", 1000);
		set("food_supply", 100);
	}
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
