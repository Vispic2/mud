inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("老鼠肉", ({"laoshu rou", "rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块鲜血淋漓肥的老鼠肉。\n");
		set("unit", "块");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
