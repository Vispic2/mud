// silver.c

inherit COMBINED_ITEM;

void create()
{
	set_name("银器", ({ "silverware", "yin qi", "silver" }));
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一个银制的餐具。\n");
		set("base_unit", "个");
		set("base_weight", 10000);
		set("no_sell", 1);
		set("unit", "些");
	}

	set_amount(1);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
