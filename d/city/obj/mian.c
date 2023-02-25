// mian.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("面", ({ "mian" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的面条。\n");
		set("unit", "碗");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
    setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
