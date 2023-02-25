// ccrystal.c 水晶残片

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "水晶残片" NOR, ({ "chipped crystal" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "一片粉色的水晶碎片。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "片");
		set("can_be_enchased", "/clone/gift/crystal");
		set("enchased_need", 3);
		set("yuanbao", 10);
		set("magic/type", "magic");
		set("magic/power", 30);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	}
	set_amount(1);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
