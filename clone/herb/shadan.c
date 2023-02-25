#include "herb.h"

void create()
{
	set_name(HIB "鲨胆" NOR, ({ "sha dan", "herb_shadan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 10000);
		set("base_weight", 35);
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/