// lurong.c

#include "herb.h"

void create()
{
	set_name(HIY "鹿茸" NOR, ({ "lurong", "herb_lurong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 10000);
		set("base_weight", 70);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
