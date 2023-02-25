// ruxiang.c

#include "herb.h"

void create()
{
	set_name(CYN "柴胡" NOR, ({ "chai hu", "herb_chaihu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 4000);
		set("base_weight", 60);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
