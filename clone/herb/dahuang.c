// dahuang.c

#include "herb.h"

void create()
{
	set_name(HIY "大黄" NOR, ({ "da huang", "herb_dahuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 7000);
		set("base_weight", 100);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
